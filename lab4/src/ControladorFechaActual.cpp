#include "../include/ControladorFechaActual.h"
#include "../include/DTFecha.h"
#include <cstddef>

ControladorFechaActual* ControladorFechaActual::instance = 0;

ControladorFechaActual::ControladorFechaActual() {
    fechaActual = new DTFecha(1,1,1900);
}

ControladorFechaActual* ControladorFechaActual::getInstancia() {
    if (instance == NULL)
        instance = new ControladorFechaActual();
    return instance;
}

void ControladorFechaActual::releaseInstancia() {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}

DTFecha ControladorFechaActual::getFechaActual(){
    return *(this->fechaActual);
}

void ControladorFechaActual::setNewFechaActual(const DTFecha& fecha) {
    delete this->fechaActual;
    this->fechaActual = new DTFecha(fecha);
}

ControladorFechaActual::~ControladorFechaActual(){
    delete this->fechaActual;
}