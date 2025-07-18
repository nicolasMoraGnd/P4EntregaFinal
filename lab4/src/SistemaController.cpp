#include "../include/SistemaController.h"
#include "../include/UsuarioHandler.h"
#include "../include/InmuebleHandler.h"
#include "../include/PublicacionHandler.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Publicacion.h"
#include "../include/DTNotificacion.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/TipoInmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"

SistemaController* SistemaController::instancia = 0;

SistemaController::SistemaController() {}
SistemaController::~SistemaController() {}

SistemaController* SistemaController::getInstancia() {
    if (instancia == 0)
        instancia = new SistemaController();
    return instancia;
}

void SistemaController::releaseInstancia() {
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}

void SistemaController::eliminarInmueble(int codigoInmueble) {
    InmuebleHandler* ih = InmuebleHandler::getInstancia();
    Inmueble* inm = ih->findInmueble(codigoInmueble);
    if(inm != 0){
        inm->desvincularInmueble();
        ih->removeInmueble(codigoInmueble);
    }
}

std::set<DTInmuebleListado*> SistemaController::listarInmuebles() {
    InmuebleHandler* ih = InmuebleHandler::getInstancia();
    std::map<int, Inmueble*> todosLosInmuebles = ih->getInmuebles();
    std::set<DTInmuebleListado*> resultado;
    for (std::map<int, Inmueble*>::iterator it = todosLosInmuebles.begin(); it != todosLosInmuebles.end(); ++it){
        Inmueble* inm = it->second;
        if (inm != 0 && inm->getPropietarioDuenio() != 0){
            int codigo = inm->getCodigo();
            std::string direccion = inm->getDireccion();
            std::string nicknameProp = inm->getPropietarioDuenio()->getNickname();
            resultado.insert(new DTInmuebleListado(codigo, direccion, nicknameProp));
        }
    }
    return resultado;
}

DTInmueble* SistemaController::detalleInmueble(int codigoInmueble) {
    InmuebleHandler* ih = InmuebleHandler::getInstancia();
    Inmueble* inm = ih->findInmueble(codigoInmueble);
    if (inm != 0)
        return inm->getDTInmueble();
    return 0; // o NULL?
}

bool SistemaController::altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    PublicacionHandler* ph = PublicacionHandler::getInstancia();
    IControladorFechaActual* cf = ControladorFechaActual::getInstancia();
    // 1
    Inmobiliaria* inmobiliaria = uh->findInmobiliaria(nicknameInmobiliaria);
    if (inmobiliaria == 0)
        return false;
    // 2
    AdministraPropiedad* adminProp = inmobiliaria->getAdministracionDeInmueble(codigoInmueble);
    if (adminProp == 0)
        return false;
    // 3
    DTFecha fechaActual = cf->getFechaActual();
    if (adminProp->existePublicacionReciente(fechaActual, tipo)) // Implmentar
        return false;

    // 7
    int nuevoCodigoPub = ph->getSiguienteCodigo();
    Publicacion* nuevaPub = new Publicacion(nuevoCodigoPub, fechaActual, tipo, texto, precio, adminProp);

    // 8
    ph->agregarPublicacion(nuevaPub);
    // Pasos 4 y 5 delegado a AdministraPropiedad en agregarPublicacion, mejor dejarlo en clases expertas
    adminProp->agregarPublicacion(nuevaPub); // Implementar

    // 6
    Inmueble* inmuebleNotif = adminProp->getInmuebleAdministrado();
    // Pasos 10-13 notifico a los suscriptores
    DTNotificacion notif = inmuebleNotif->crearDTNotificacion(inmobiliaria->getNickname(), texto, tipo);
    inmobiliaria->notificarSuscriptores(notif);
    return true; // Si todo sale bien se cargo la publicacion y devuelvo true
}

std::set<DTPublicacion*> SistemaController::listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInm) {
    PublicacionHandler* ph = PublicacionHandler::getInstancia();
    std::map<int, Publicacion*> todasLasPublicaciones = ph->getPublicaciones();
    std::set<DTPublicacion*> resultado; 
    for (std::map<int, Publicacion*>::iterator it = todasLasPublicaciones.begin(); it != todasLasPublicaciones.end(); ++it){
        Publicacion* pub = it->second;
        bool filtroTipoPub = pub->getTipo() == tipo;
        bool filtroPrecio = pub->getPrecio() >= precioMin && pub->getPrecio() <= precioMax;
        bool filtroTipoInmueble = false;
        if (tipoInm == Todos)
            filtroTipoInmueble = true;
        else{
            Inmueble* inm = pub->getAdministracionPropiedad()->getInmuebleAdministrado();
            if(tipoInm == TI_Casa && dynamic_cast<Casa*>(inm) != 0)
                filtroTipoInmueble = true;
            else if(tipoInm == TI_Apartamento && dynamic_cast<Apartamento*>(inm) != 0)
                filtroTipoInmueble = true;
        }
        if (pub->esActiva() && filtroTipoPub && filtroPrecio && filtroTipoInmueble)
            resultado.insert(pub->getDTPublicacion());
    }
    return resultado;
}

DTInmueble* SistemaController::detalleInmueblePublicacion(int codigoPublicacion) {
    PublicacionHandler* ph = PublicacionHandler::getInstancia();
    Publicacion* pub = ph->findPublicacion(codigoPublicacion);
    if(pub != 0){
        Inmueble* inm = pub->getAdministracionPropiedad()->getInmuebleAdministrado();
        return inm->getDTInmueble();
    }
    return 0; // o NULL?
}