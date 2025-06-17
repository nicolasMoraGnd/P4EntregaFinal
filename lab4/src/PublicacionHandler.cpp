#include "../include/PublicacionHandler.h"

PublicacionHandler* PublicacionHandler::instancia = NULL;
PublicacionHandler::PublicacionHandler(){
}

PublicacionHandler* PublicacionHandler::getInstancia(){
    if(instancia== NULL){
        instancia = new PublicacionHandler();
    }
    return instancia;
}

void PublicacionHandler::agregarPublicacion(Publicacion* publicacion){
    mapPublicaciones.insert(std::make_pair(publicacion->getCodigo(), publicacion));
}

std::map<int, Publicacion*> PublicacionHandler::getPublicaciones(){
    return mapPublicaciones;
}