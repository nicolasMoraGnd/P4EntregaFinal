#include "../include/ControladorNotificaciones.h"

/////////////////////////////////////////////////////////////////////////////////////
// ESTO ES ALGO QUE HIZO EL GEMINI CUANDO PEDI AYUDA PARA HACER EL OBSERVER. -Marcos
/////////////////////////////////////////////////////////////////////////////////////

// Inicialización de la instancia Singleton
ControladorNotificaciones* ControladorNotificaciones::instance = NULL;

// Constructor privado
ControladorNotificaciones::ControladorNotificaciones() {
    // Inicializaciones si son necesarias
}

// Método para obtener la instancia Singleton 
ControladorNotificaciones* ControladorNotificaciones::getInstance() {
    if (instance == NULL) {
        instance = new ControladorNotificaciones();
    }
    return instance;
}

// Método para agregar un observador 
void ControladorNotificaciones::agregarObserver(IObserver* o) {
    if (o != NULL) {
        observers.insert(o);
    }
}

// Método para eliminar un observador 
void ControladorNotificaciones::eliminarObserver(IObserver* o) {
    if (o != NULL) {
        observers.erase(o);
    }
}

// Método para notificar a todos los observadores 
void ControladorNotificaciones::notificarObservadores(DTNotificacion* notificacion) {
    for (IObserver* obs : observers) {
        if (obs != NULL) {
            obs->notify(notificacion);
        }
    }
    
    // delete notificacion; // Esto dependerá de quién es el dueño del DTNotificacion
}

// Implementaciones placeholder para los casos de uso específicos:
void ControladorNotificaciones::suscribirseNotificaciones(std::string nicknameCliente) {
    // Lógica para que un Cliente se suscriba.
    // Aquí buscarías al Cliente por su nickname y lo agregarías como observador.
    // Esto implicaría que Cliente debe implementar IObserver.
    // Ejemplo: Cliente* cliente = buscarCliente(nicknameCliente);
    // if (cliente) agregarObserver(cliente);
}

void ControladorNotificaciones::consultaNotificaciones(std::string nicknameCliente) {
    // Lógica para que un Cliente consulte sus notificaciones.
    // Un Cliente podría tener un historial de DTNotificacion recibidos.
}

void ControladorNotificaciones::eliminarSuscripciones(std::string nicknameCliente) {
    // Lógica para que un Cliente elimine su suscripción.
    // Ejemplo: Cliente* cliente = buscarCliente(nicknameCliente);
    // if (cliente) eliminarObserver(cliente);
}

// Destructor para liberar la instancia Singleton
ControladorNotificaciones::~ControladorNotificaciones() {
    // Limpiar el set de observers si es necesario (ej. si los observers son dueños de memoria)
    // En este caso, los observers son punteros y no son propiedad de este controlador.
    // La liberación de memoria de los observers la debe manejar quien los creó.
}