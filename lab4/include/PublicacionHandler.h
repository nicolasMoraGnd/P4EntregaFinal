#ifndef PUBLICACIONHANDLER_H
#define PUBLICACIONHANDLER_H

#include <map>
#include "Publicacion.h"

class PublicacionHandler {
private:
    std::map<int, Publicacion*> mapPublicaciones;
    static PublicacionHandler* instancia;
    PublicacionHandler(); // Constructor privado para el Singleton

public:
    static PublicacionHandler* getInstance();
    static void releaseInstance();
    ~PublicacionHandler();

    void agregarPublicacion(Publicacion* publicacion);
    Publicacion* findPublicacion(int codigo);
    std::map<int, Publicacion*> getPublicaciones();
};

#endif