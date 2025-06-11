#include "../include/ControladorFechaActual.h"
#include "../include/DTFecha.h"
#include <cstddef>

ControladorFechaActual* ControladorFechaActual::instance = NULL;

ControladorFechaActual::ControladorFechaActual() {
    fechaActual = new DTFecha(1,1,1900);
}

ControladorFechaActual* ControladorFechaActual::getInstance() {
    if (instance == NULL)
        instance = new ControladorFechaActual();
    return instance;
}

DTFecha ControladorFechaActual::getFechaActual(){
    return new DTFecha(fechaActual);
    /*Esto puede ser una fuga de memoria terrible, cada vez que llamamos getFechaActual(), se crea en el heap una nueva copia del objeto DTFecha.
    Es decir, quien llama a esta funcion recibe un puntero y se vuelve responsable de liberarlo.
    Aunque en el menu.cpp en teoria se deberia de manejar bien, es algo muy fragil y propenso a errores, si nos olvidamos de un delete tenemos una fuga de memoria.
    Posible solucion: return *(this->fechaActual); Devolviendo una copia del objeto, no un puntero, haciendo que el que llame no se preocupe por la memoria.
    */
}

void ControladorFechaActual::setNewFechaActual(const DTFecha& fecha) {
    delete this->fechaActual;
    this->fechaActual = new DTFecha(fecha);
}

ControladorFechaActual::~ControladorFechaActual(){
    delete this->fechaActual;
    instance = NULL; // Muy sus
    /*Un destructor tiene que eliminar memoria de un objeto el cual va a ser eliminado
    pero el puntero instance no es de un objeto, es una variable estatica (de la clase),
    que funciona como un switch global para saber si el singleton fue creado.
    O sea, si llamamos en algun momento a delete instance; se ejecuta el destructor del objeto,
    el destructor ademas de borrar la fecha, pone el puntero global instance a NULL, y si cualquier otra parte del programa llama
    a getinstance() despues de esto, el if instance==NULL sera verdadero y se creara un objeto Singleton completamente nuevo
    rompiendo el proposito del Singleton que es tener una sola instancia,
    puediendo resetear fechas que ya habia guardado o peor aun, dejar punteros colgando a objetos ya destruidos*/
    // Solucion ELIMINAR ESA LINEA.
}