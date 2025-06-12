#ifndef CONTROLADORNOTIFICACIONES_H
#define CONTROLADORNOTIFICACIONES_H

#include <set>
#include <string>
#include "IObserver.h"       // Para la interfaz IObserver
#include "DTNotificacion.h"  // Para el tipo de dato de la notificación
#include "Cliente.h"         // Necesario si se va a manejar la relación directa con Cliente

// El Subject (Sujeto Observable)
class ControladorNotificaciones {
private:
    static ControladorNotificaciones* instance; // Instancia Singleton
    std::set<IObserver*> observers;             // Conjunto de observadores suscritos

    // Constructor privado para el patrón Singleton
    ControladorNotificaciones(); 

public:
    // Método para obtener la instancia Singleton
    static ControladorNotificaciones* getInstance();

    // Métodos para registrar/desregistrar observadores 
    void agregarObserver(IObserver* o);    // Permite registrar un observador nuevo
    void eliminarObserver(IObserver* o); // Permite desregistrar un observador

    // Método para notificar a todos los observadores 
    // Este método será llamado por otras partes del sistema cuando ocurra un evento relevante
    void notificarObservadores(DTNotificacion* notificacion); 

    // Métodos específicos para los casos de uso de suscripciones
    // Estos podrían ser parte de la interfaz IControladorUsuario o IControladorCliente si tuvieras uno
    // Pero por ahora, los pongo aquí ya que este controlador maneja las notificaciones
    void suscribirseNotificaciones(std::string nicknameCliente);
    void consultaNotificaciones(std::string nicknameCliente);
    void eliminarSuscripciones(std::string nicknameCliente);
    
    // Destructor
    ~ControladorNotificaciones();
};

#endif