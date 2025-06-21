#include "../include/DTPublicacion.h"
<<<<<<< HEAD
#include "../include/TipoPublicacion.h"

DTPublicacion::DTPublicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo,std::string texto, float precio, std::string inmobiliaria, bool activa) {
    this->codigo = codigo;
    this->fecha = new DTFecha(fecha);
    this->tipo = tipo;
    this->texto = texto;
    this->precio = precio;
    this->inmobiliaria = inmobiliaria;
    this->activa = activa;
}
=======
#include "../include/DTFecha.h"

DTPublicacion::DTPublicacion(int codigo, const DTFecha& fecha, const std::string& texto, float precio, const std::string& inmobiliaria)
    : codigo(codigo), fecha(fecha), texto(texto), precio(precio), inmobiliaria(inmobiliaria) {}

DTPublicacion::~DTPublicacion(){}
>>>>>>> main

int DTPublicacion::getCodigo() {
    return this->codigo;
}

DTFecha DTPublicacion::getFecha() {
    return this->fecha;
}

TipoPublicacion DTPublicacion::getTipoPublicacion(){
    return tipo;
}

std::string DTPublicacion::getTexto() {
    return this->texto;
}

float DTPublicacion::getPrecio() {
<<<<<<< HEAD
    return precio;
=======
    return this->precio;
>>>>>>> main
}

bool DTPublicacion::getActiva() {
    return activa;
}

std::string DTPublicacion::getInmobiliaria() {
    return this->inmobiliaria;
}