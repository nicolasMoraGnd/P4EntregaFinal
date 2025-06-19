#include "../include/PublicacionHandler.h"
#include "../include/Publicacion.h"
#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include <cstddef>
#include <set>

PublicacionHandler* PublicacionHandler::instancia = NULL;

PublicacionHandler::PublicacionHandler() : ultimoCodigo(0) {}

// El destructor recorre el mapa y libera la memoria de cada Publicacion
PublicacionHandler::~PublicacionHandler() {
    for (std::map<int, Publicacion*>::iterator it = mapPublicaciones.begin(); it != mapPublicaciones.end(); ++it)
        delete it->second;
    mapPublicaciones.clear();
}

PublicacionHandler* PublicacionHandler::getInstance() {
    if (instancia == NULL)
        instancia = new PublicacionHandler();
    return instancia;
}

void PublicacionHandler::agregarPublicacion(Publicacion* publicacion) {
    if (publicacion != NULL)
        mapPublicaciones[publicacion->getCodigo()] = publicacion;
}

std::map<int, Publicacion*> PublicacionHandler::getPublicaciones(){
    return mapPublicaciones;
}

Publicacion* PublicacionHandler::findPublicacion(int codigo) {
    std::map<int, Publicacion*>::iterator it = mapPublicaciones.find(codigo);
    if (it != mapPublicaciones.end())
        return it->second;
    return 0;
}

int PublicacionHandler::getSiguienteCodigo() {
    this->ultimoCodigo++;
    return this->ultimoCodigo;
}

std::set<DTPublicacion*> PublicacionHandler::getPublicaciones(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInm) {
    std::set<DTPublicacion*> resultado;
    for (std::map<int, Publicacion*>::iterator it = this->mapPublicaciones.begin(); it != this->mapPublicaciones.end(); ++it){
        Publicacion* pub = it->second;
        bool filtroActiva = pub->esActiva();
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
        if (filtroActiva && filtroTipoPub && filtroPrecio && filtroTipoInmueble)
            resultado.insert(pub->getDTPublicacion());
    }
    return resultado;
}