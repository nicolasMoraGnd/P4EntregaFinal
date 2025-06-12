#ifndef INMUEBLEHANDLER_H
#define INMUEBLEHANDLER_H
#include "Inmueble.h"
#include <map>

using namespace std;

class InmuebleHandler{
    private:
        static InmuebleHandler* instancia;
        map<int, Inmueble*> inmuebles;
        InmuebleHandler();
    public:
        static InmuebleHandler* getInstance();
        void addInmueble(Inmueble* inmueble);
        void removeInmueble(int);
        Inmueble* findInmueble(int);
};
#endif