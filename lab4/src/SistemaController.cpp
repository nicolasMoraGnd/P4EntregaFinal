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

SistemaController* SistemaController::instancia = 0;

SistemaController::SistemaController() {}
SistemaController::~SistemaController() {}

SistemaController* SistemaController::getInstance() {
    if (instancia == 0)
        instancia = new SistemaController();
    return instancia;
}

void SistemaController::eliminarInmueble(int codigoInmueble) {
    InmuebleHandler* ih = InmuebleHandler::getInstance();
    Inmueble* inm = ih->findInmueble(codigoInmueble);
    if(inm != 0){
        inm->desvincularInmueble();
        ih->removeInmueble(codigoInmueble);
    }
}

std::set<DTInmuebleListado*> SistemaController::listarInmuebles() {
    InmuebleHandler* ih = InmuebleHandler::getInstance();
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
    InmuebleHandler* ih = InmuebleHandler::getInstance();
    Inmueble* inm = ih->findInmueble(codigoInmueble);
    if (inm != 0)
        return inm->getDTInmueble();
    return 0; // o NULL?
}

bool SistemaController::altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio) {
    UsuarioHandler* uh = UsuarioHandler::getInstancia(); // babeado bebeeeeee
    PublicacionHandler* ph = PublicacionHandler::getInstance();
    IControladorFechaActual* cf = ControladorFechaActual::getInstance();
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
    DTNotificacion notif(inmobiliaria->getNickname(), inmuebleNotif->getCodigo(), texto, tipo, inmuebleNotif->esCasa()); // 9 esCasa()
    inmobiliaria->notificarSuscriptores(notif);
    return true; // Si todo sale bien se cargo la publicacion y devuelvo true
}

std::set<DTPublicacion*> SistemaController::listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInm) {
    PublicacionHandler* ph = PublicacionHandler::getInstance();
    return ph->getPublicaciones(tipo, precioMin, precioMax, tipoInm);
}

DTInmueble* SistemaController::detalleInmueblePublicacion(int codigoPublicacion) {
    PublicacionHandler* ph = PublicacionHandler::getInstance();
    Publicacion* pub = ph->findPublicacion(codigoPublicacion);
    if(pub != 0){
        Inmueble* inm = pub->getAdministracionPropiedad()->getInmuebleAdministrado();
        return inm->getDTInmueble();
    }
    return 0; // o NULL?
}