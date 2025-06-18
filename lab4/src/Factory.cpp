#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/SistemaController.h"
#include "../include/UsuarioController.h"
#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IUsuarioController* Factory::getIUsuarioController(){
    return UsuarioController::getInstance();
}

ISistemaController* Factory::getISistemaController(){
    return SistemaController::getInstance();
}