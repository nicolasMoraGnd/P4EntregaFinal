#include "../include/InmuebleHandler.h"
#include "../include/Inmueble.h"
#include <utility>

InmuebleHandler* InmuebleHandler::instancia = nullptr;

InmuebleHandler::InmuebleHandler() {}

InmuebleHandler* InmuebleHandler::getInstance() {
    if (instancia == nullptr) {
        instancia = new InmuebleHandler();
    }
    return instancia;
}

void InmuebleHandler::addInmueble(Inmueble* inmueble) {
    if (inmueble != nullptr) {
        inmuebles[inmueble->getCodigo()] = inmueble;
    }
}

// RECORDATORIO: Esta funcion solo debe ser llamada por un controlador que ya se encargo de eliminar todas las asociaciones del inmueble.
void InmuebleHandler::removeInmueble(int codigoInmueble) {
    std::map<int, Inmueble*>::iterator it = this->inmuebles.find(codigoInmueble);
    if (it != this->inmuebles.end()) {
        Inmueble* inmueble = it->second;
        this->inmuebles.erase(it);
        delete inmueble;
    }
}

Inmueble* InmuebleHandler::findInmueble(int codigoInmueble) {
    std::map<int, Inmueble*>::iterator it = this->inmuebles.find(codigoInmueble);
    if (it != this->inmuebles.end()) {
        return it->second;
    }
    return nullptr;
}

InmuebleHandler::~InmuebleHandler() {
    for (std::map<int, Inmueble*>::iterator it = this->inmuebles.begin(); it != this->inmuebles.end(); ++it)
        delete it->second;
    this->inmuebles.clear();
}