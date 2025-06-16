#include "../include/PublicacionHandler.h"
#include "../include/Publicacion.h"
#include <cstddef>

PublicacionHandler* PublicacionHandler::instancia = 0;

PublicacionHandler::PublicacionHandler() {}

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