#include "../include/DTPublicacion.h"
#include "../include/DTFecha.h"

DTPublicacion::DTPublicacion(int codigo, const DTFecha& fecha, const std::string& texto, float precio, const std::string& inmobiliaria)
    : codigo(codigo), fecha(fecha), texto(texto), precio(precio), inmobiliaria(inmobiliaria) {}

DTPublicacion::~DTPublicacion(){}

int DTPublicacion::getCodigo() {
    return this->codigo;
}

DTFecha DTPublicacion::getFecha() {
    return this->fecha;
}

std::string DTPublicacion::getTexto() {
    return this->texto;
}

float DTPublicacion::getPrecio() {
    return this->precio;
}

std::string DTPublicacion::getInmobiliaria() {
    return this->inmobiliaria;
}