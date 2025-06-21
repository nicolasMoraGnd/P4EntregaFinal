#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
<<<<<<< HEAD
#include "../include/ControladorNotificaciones.h"
=======
#include "../include/SistemaController.h"
#include "../include/UsuarioController.h"
>>>>>>> main
#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstancia() {
    if (instance == NULL)
        instance = new Factory();
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
<<<<<<< HEAD
    return ControladorFechaActual::getInstance();
}

ControladorNotificaciones* Factory::getControladorNotificaciones() {
    return ControladorNotificaciones::getInstance(); // ¡Ahora esto debería compilar!
}

/*
IControladorUsuario* Factory::getControladorUsuario() {
    // Retorna la instancia de tu ControladorUsuario
    // Ejemplo: return UsuarioHandler::getInstance(); // Si UsuarioHandler actúa como controlador
    return nullptr; // Placeholder
}

IControladorInmueble* Factory::getControladorInmueble() {
    // Retorna la instancia de tu ControladorInmueble
    // Ejemplo: return InmuebleHandler::getInstance(); // Si InmuebleHandler actúa como controlador
    return nullptr; // Placeholder
}
*/

=======
    return ControladorFechaActual::getInstancia();
}

IUsuarioController* Factory::getIUsuarioController(){
    return UsuarioController::getInstancia();
}

ISistemaController* Factory::getISistemaController(){
    return SistemaController::getInstancia();
}
>>>>>>> main
