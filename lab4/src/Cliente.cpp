#include "../include/Cliente.h"
#include "../include/Inmobiliaria.h"

Cliente::Cliente(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento)
    : Usuario(nickname, contrasena, nombre, email), apellido(apellido), documento(documento) {
    // El cuerpo del constructor puede quedar vacio si toda la inicializacion se hace en la lista
}

Cliente::~Cliente() {}

std::string Cliente::getApellido() const {
    return this->apellido;
}

std::string Cliente::getDocumento() const {
    return this->documento;
}

void Cliente::setApellido(const std::string& apellido) {
    this->apellido = apellido;
}

void Cliente::setDocumento(const std::string& documento) {
    this->documento = documento;
}

void Cliente::notificar(const DTNotificacion& notif) {
    this->notificacionesPendientes.push_back(notif);
}

void Cliente::suscribirseAInmobiliaria(Inmobiliaria* inm){
    this->suscripciones.insert(inm);
    inm->suscribir(this);
}

void Cliente::desuscribirseDeInmobiliaria(Inmobiliaria* inm){
    this->suscripciones.erase(inm);
    inm->desuscribir(this);
}

bool Cliente::estaSuscritoA(Inmobiliaria* inm) const{
    return this->suscripciones.count(inm) == 1;
}

std::list<DTNotificacion> Cliente::getNotificacionesPendientes() const {
    return this->notificacionesPendientes;
}

void Cliente::limpiarNotificaciones() {
    this->notificacionesPendientes.clear();
}

DTUsuario* Cliente::getDTUsuario() const {
    return new DTUsuario(getNickname(), getNombre());
}