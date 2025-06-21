#include "../include/DTInmuebleAdministrado.h"

DTInmuebleAdministrado::DTInmuebleAdministrado(int codigo, const std::string& direccion, const DTFecha& fechaComienzo)
    : codigo(codigo), direccion(direccion), fechaComienzo(fechaComienzo) {}

DTInmuebleAdministrado::~DTInmuebleAdministrado(){}

int DTInmuebleAdministrado::getCodigo() {
    return this->codigo;
}

std::string DTInmuebleAdministrado::getDireccion() {
    return this->direccion;
}

DTFecha DTInmuebleAdministrado::getFechaComienzo() {
    return this->fechaComienzo;
}