#include "../include/DTPublicacion.h"
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

int DTPublicacion::getCodigo() {
    return codigo;
}

DTFecha* DTPublicacion::getFecha() {
    return fecha;
}

TipoPublicacion DTPublicacion::getTipoPublicacion(){
    return tipo;
}

std::string DTPublicacion::getTexto() {
    return texto;
}

float DTPublicacion::getPrecio() {
    return precio;
}

bool DTPublicacion::getActiva() {
    return activa;
}

std::string DTPublicacion::getInmobiliaria() {
    return inmobiliaria;
}

DTPublicacion::~DTPublicacion(){
    delete fecha;
}