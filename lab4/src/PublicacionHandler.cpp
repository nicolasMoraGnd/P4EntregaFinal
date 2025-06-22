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

PublicacionHandler::~PublicacionHandler() {
    mapPublicaciones.clear();
}

void PublicacionHandler::removePublicacion(int codigo) {
    mapPublicaciones.erase(codigo);
}

void PublicacionHandler::releaseInstancia() {
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}

PublicacionHandler* PublicacionHandler::getInstancia() {
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