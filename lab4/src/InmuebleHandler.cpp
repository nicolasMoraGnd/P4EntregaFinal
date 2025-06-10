#include "../include/InmuebleHandler.h"
#include "../include/Inmueble.h"
#include <map>
#include <cstddef>

InmuebleHandler* InmuebleHandler::instancia = nullptr;

InmuebleHandler::InmuebleHandler(){};

InmuebleHandler* InmuebleHandler::getInstance(){
    if (instancia == nullptr)
        instancia = new InmuebleHandler();
    return instancia;
};

void InmuebleHandler::removeInmueble(int codigoInmueble){
    map<int, Inmueble*>::iterator it = this->inmuebles.find(codigoInmueble);
    if (it != this->inmuebles.end())
    {
        Inmueble* inmueble = it->second;
        this->inmuebles.erase(codigoInmueble);
        delete inmueble;
    }
};

Inmueble* InmuebleHandler::findInmueble(int codigoInmueble){
    map<int, Inmueble*>::iterator it = this->inmuebles.find(codigoInmueble);
    if (it != this->inmuebles.end())
        return it->second;
    return nullptr;
};
