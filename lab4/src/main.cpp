#include "../include/Menu.h"
#include "../include/Factory.h"
#include "../include/CargaDatos.h"
#include "../include/UsuarioController.h"
#include "../include/SistemaController.h"
#include "../include/ControladorFechaActual.h"
#include "../include/UsuarioHandler.h"
#include "../include/InmuebleHandler.h"
#include "../include/PublicacionHandler.h"
#include <iostream>

void limpiarRecursos() {     
        CargaDatos::releaseInstancia();
        UsuarioController::releaseInstancia();
        SistemaController::releaseInstancia();
        ControladorFechaActual::releaseInstancia(); 

        InmuebleHandler::releaseInstancia();
        UsuarioHandler::releaseInstancia();
        
        PublicacionHandler::releaseInstancia();

        Factory::releaseInstancia();

        std::cout << "Recursos del sistema liberados correctamente." << std::endl;
    }

int main() {

    while (true) {
        mostrarMenu();
        int opcion = obtenerOpcion();
        // Si la opción es 0, salimos del bucle para limpiar y terminar.
        if (opcion == 0) {
            break; 
        }
        ejecutarOpcion(opcion);
        std::cout << std::endl;
    }

    limpiarRecursos();
    // El 'exit(0)' que estaba en ejecutarOpcion se maneja ahora aquí.
    std::cout << "Saliendo del programa..." << std::endl;

    return 0;
}