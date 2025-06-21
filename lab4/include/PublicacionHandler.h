#ifndef PUBLICACIONHANDLER_H
#define PUBLICACIONHANDLER_H

#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Publicacion.h"
#include <map>

class PublicacionHandler {
private:
    std::map<int, Publicacion*> mapPublicaciones;
    static PublicacionHandler* instancia;
    PublicacionHandler(); // Constructor privado para el Singleton
    int ultimoCodigo;

public:
    static PublicacionHandler* getInstancia();
    static void releaseInstance();
    ~PublicacionHandler();

    void agregarPublicacion(Publicacion* publicacion);
    Publicacion* findPublicacion(int codigo);
    std::map<int, Publicacion*> getPublicaciones();
    int getSiguienteCodigo();
};

#endif