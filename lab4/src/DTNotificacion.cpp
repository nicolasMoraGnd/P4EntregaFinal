#include "../include/DTNotificacion.h"

<<<<<<< HEAD
DTNotificacion::DTNotificacion(std::string nickInmo, int codigo, std::string texto, TipoPublicacion tipo, bool esCasa) {
    this->nickInmo = nickInmo;
    this->codigo = codigo;
    this->texto = texto;
    this->tipo = tipo;
    this->esCasa = esCasa;
}

=======
DTNotificacion::DTNotificacion(const std::string& nickInmo, int codigo, const std::string& texto, TipoPublicacion tipo, bool esCasa)
    : nickInmo(nickInmo), codigo(codigo), texto(texto), tipo(tipo), esCasa(esCasa) {}

DTNotificacion::~DTNotificacion() {

}
>>>>>>> main

std::string DTNotificacion::getNickInmo() const {
    return this->nickInmo;
}

int DTNotificacion::getCodigo() const {
    return this->codigo;
}

std::string DTNotificacion::getTexto() const {
    return this->texto;
}

TipoPublicacion DTNotificacion::getTipo() const {
    return this->tipo;
}

bool DTNotificacion::getEsCasa() const {
    return this->esCasa;
<<<<<<< HEAD
}


DTNotificacion::~DTNotificacion() {

=======
>>>>>>> main
}