#include "../include/Propietario.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTNotificacion.h"

Propietario::Propietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono)
    : Usuario(nickname, contrasena, nombre, email), cuentaBancaria(cuentaBancaria), telefono(telefono) {}

// Como el Propietario es "dueño" de sus Inmuebles, su destructor debe liberarlos.
Propietario::~Propietario() {
    for (std::set<Inmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it)
        delete *it;
    inmuebles.clear();
}

std::string Propietario::getCuentaBancaria() const {
    return this->cuentaBancaria;
}

std::string Propietario::getTelefono() const {
    return this->telefono;
}

void Propietario::agregarInmueble(Inmueble* inm) {
    this->inmuebles.insert(inm);
}

void Propietario::desvincularPropietarioInmueble(Inmueble* inm) {
    this->inmuebles.erase(inm);
}

std::set<Inmueble*> Propietario::getInmuebles() const {
    return this->inmuebles;
}

void Propietario::notificar(const DTNotificacion& notif) {
    this->notificacionesPendientes.push_back(notif);
}

void Propietario::suscribirseAInmobiliaria(Inmobiliaria* inm) {
    this->suscripciones.insert(inm);
    inm->suscribir(this);
}

void Propietario::desuscribirseDeInmobiliaria(Inmobiliaria* inm) {
    this->suscripciones.erase(inm);
    inm->desuscribir(this);
}

bool Propietario::estaSuscritoA(Inmobiliaria* inm) const {
    return this->suscripciones.count(inm) == 1;
}

std::list<DTNotificacion> Propietario::getNotificacionesPendientes() const {
    return this->notificacionesPendientes;
}

void Propietario::limpiarNotificaciones() {
    this->notificacionesPendientes.clear();
}

void Propietario::agregarInmobiliariaQueRepresenta(Inmobiliaria* inm) {
    this->inmobiliariasQueRepresentan.insert(inm);
}

void Propietario::quitarInmobiliariaQueRepresenta(Inmobiliaria* inm) {
    this->inmobiliariasQueRepresentan.erase(inm);
}