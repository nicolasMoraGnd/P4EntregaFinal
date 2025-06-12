#ifndef PUBLICACIONHANDLER_H
#define PUBLICACIONHANDLER_H
#include <map>
#include <set>
#include "Publicacion.h"


class PublicacionHandler{
    private:
        std::map<int, Publicacion*> mapPublicaciones;
        static PublicacionHandler* instancia;
        PublicacionHandler();

    public:
        PublicacionHandler* getInstancia();
        std::map<int, Publicacion*> getPublicaciones();
        void agregarPublicacion(Publicacion* publicacion);
};