#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "IObserver.h"
#include "DTNotificacion.h"
#include <string>
#include <set>
#include <list>

class Inmobiliaria;

class Cliente : public Usuario, public IObserver { 
private:
    std::string apellido;
    std::string documento;

    std::set<Inmobiliaria*> suscripciones;
    std::list<DTNotificacion> notificacionesPendientes;

public:
    Cliente(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento);
    virtual ~Cliente();

    std::string getApellido() const;
    std::string getDocumento() const;
    void setApellido(const std::string& apellido);
    void setDocumento(const std::string& documento);

    virtual void notificar(const DTNotificacion& notif);
    void suscribirseAInmobiliaria(Inmobiliaria* inm);
    void desuscribirseDeInmobiliaria(Inmobiliaria* inm);
    bool estaSuscritoA(Inmobiliaria* inm) const;
    std::list<DTNotificacion> getNotificacionesPendientes() const;
    void limpiarNotificaciones();

    DTUsuario* getDTUsuario() const;
};

#endif