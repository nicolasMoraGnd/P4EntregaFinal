#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>
#include "DTNotificacion.h" // Incluimos el DTNotificacion que será el "dato" de la notificación

// La interfaz IObserver
class IObserver {
public:
    // Método virtual puro que los observadores deben implementar
    // Recibe un DTNotificacion que contiene la información del evento
    virtual void notify(DTNotificacion* notificacion) = 0; 
    
    // Virtual destructor para asegurar la correcta liberación de memoria de las clases derivadas
    virtual ~IObserver() {} 
};

#endif