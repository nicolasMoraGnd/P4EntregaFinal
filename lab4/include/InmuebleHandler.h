#ifndef INMUEBLEHANDLER_H
#define INMUEBLEHANDLER_H

#include "Inmueble.h"
#include <map>

class InmuebleHandler {
private:
    std::map<int, Inmueble*> inmuebles;
    static InmuebleHandler* instancia;
    InmuebleHandler();
    int ultimoCodigo;

public:
    static InmuebleHandler* getInstancia();
    ~InmuebleHandler();
    static void releaseInstancia();
    int getSiguienteCodigo();
    void addInmueble(Inmueble* inmueble);
    void removeInmueble(int codigoInmueble);
    Inmueble* findInmueble(int codigoInmueble);
    std::map<int, Inmueble*> getInmuebles() const;
};

#endif