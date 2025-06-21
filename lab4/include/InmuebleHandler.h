#ifndef INMUEBLEHANDLER_H
#define INMUEBLEHANDLER_H

#include <map>

class Inmueble;

class InmuebleHandler {
private:
    std::map<int, Inmueble*> inmuebles;
    static InmuebleHandler* instancia;
    InmuebleHandler();
    int ultimoCodigo;

public:
    static InmuebleHandler* getInstancia();
    ~InmuebleHandler();

    int getSiguienteCodigo();
    void addInmueble(Inmueble* inmueble);
    void removeInmueble(int codigoInmueble);
    Inmueble* findInmueble(int codigoInmueble);
    std::map<int, Inmueble*> getInmuebles() const;
};

#endif