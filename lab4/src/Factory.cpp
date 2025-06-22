#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/SistemaController.h"
#include "../include/UsuarioController.h"
#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {}

Factory::~Factory() {}

Factory* Factory::getInstancia() {
    if (instance == NULL)
        instance = new Factory();
    return instance;
}

IControladorFechaActual* Factory::getIControladorFechaActual(){
    return ControladorFechaActual::getInstancia();
}

IUsuarioController* Factory::getIUsuarioController(){
    return UsuarioController::getInstancia();
}

ISistemaController* Factory::getISistemaController(){
    return SistemaController::getInstancia();
}

void Factory::releaseInstancia() {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}