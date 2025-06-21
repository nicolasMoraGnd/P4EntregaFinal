#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include "Usuario.h"
#include "IObserver.h"
#include "DTNotificacion.h"
#include <string>
#include <set>
#include <list>

class Inmueble;
class Inmobiliaria;
class DTInmuebleListado;

class Propietario : public Usuario, public IObserver {
private:
    std::string cuentaBancaria;
    std::string telefono;
    
    std::set<Inmueble*> inmuebles;
    std::set<Inmobiliaria*> inmobiliariasQueRepresentan;
    std::set<Inmobiliaria*> suscripciones;

    std::list<DTNotificacion> notificacionesPendientes;

public:
    Propietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono);
    virtual ~Propietario();

    std::string getCuentaBancaria() const;
    std::string getTelefono() const;

    void agregarInmueble(Inmueble* inm);
    void desvincularPropietarioInmueble(Inmueble* inm);
    std::set<Inmueble*> getInmuebles() const;

    std::set<DTInmuebleListado*> getInmueblesNoAdmin(const Inmobiliaria* inm) const;

    virtual void notificar(const DTNotificacion& notif);
    void suscribirseAInmobiliaria(Inmobiliaria* inm);
    void desuscribirseDeInmobiliaria(Inmobiliaria* inm);
    bool estaSuscritoA(Inmobiliaria* inm) const;
    std::list<DTNotificacion> getNotificacionesPendientes() const;
    void limpiarNotificaciones();
    
    void agregarInmobiliariaQueRepresenta(Inmobiliaria* inm);
    void quitarInmobiliariaQueRepresenta(Inmobiliaria* inm);

    DTUsuario* getDTUsuario() const;
};

#endif