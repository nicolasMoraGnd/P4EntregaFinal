#include "../include/DTInmuebleListado.h"

DTInmuebleListado::DTInmuebleListado(int codigo, std::string direccion, std::string propietario) 
    : codigo(codigo), direccion(), propietario(propietario) {}

int DTInmuebleListado::getCodigo() {
    return codigo;
}

std::string DTInmuebleListado::getDireccion() {
    return direccion;
}

std::string DTInmuebleListado::getPropietario() {
    return propietario;
}