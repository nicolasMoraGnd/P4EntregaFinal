#include "../include/DTUsuario.h"
#include "../include/Propietario.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTNotificacion.h"
#include "../include/DTInmuebleListado.h"


Propietario::Propietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono)
    : Usuario(nickname, contrasena, nombre, email), cuentaBancaria(cuentaBancaria), telefono(telefono) {}

Propietario::~Propietario() {
    inmuebles.clear();
    inmobiliariasQueRepresentan.clear();
    suscripciones.clear();
    notificacionesPendientes.clear();
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

DTUsuario* Propietario::getDTUsuario() const {
    return new DTUsuario(getNickname(), getNombre());
}

std::set<DTInmuebleListado*> Propietario::getInmueblesNoAdmin(const Inmobiliaria* inm) const {
    std::set<DTInmuebleListado*> resultado;
    for (std::set<Inmueble*>::const_iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
            Inmueble* in = *it;
            // si no va a ser admin por la propiety pasadusken
            if (!in->esAdministradoPor(inm)) {
                int codigo = in->getCodigo(); // retortna el codigo
                std::string direccion = in->getDireccion();
                //creamo el coso
                DTInmuebleListado* dt = new DTInmuebleListado(codigo, direccion, getNickname());
                resultado.insert(dt);
            }
        }
    return resultado;
}