#include "../include/PublicacionHandler.h"

PublicacionHandler* PublicacionHandler::instance = NULL;

PublicacionHandler* PublicacionHandler::getInstancia(){
    if(instancia== NULL){
        instancia = new PublicacionHandler();
    }
    return instancia
}

void PublicacionHandler::agregarPublicacion(Publicacion* publicacion){
    mapPublicaciones.insert(std::make_pair(publicacion->getCodigo(), publicacion));
}

std::map<int, Publicacion*> PublicacionHandler::getPublicaciones(){
    return mapPublicaciones
}