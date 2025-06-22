#include "../include/DTInmueble.h"

DTInmueble::DTInmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion) 
    : codigo(codigo), direccion(direccion), numeroPuerta(numeroPuerta), superficie(superficie), anioConstruccion(anioConstruccion){}

DTInmueble::~DTInmueble(){}

int DTInmueble::getCodigo() {
    return codigo;
}

std::string DTInmueble::getDireccion() {
    return direccion;
}

int DTInmueble::getNumeroPuerta() {
    return numeroPuerta;
}

int DTInmueble::getSuperficie() {
    return superficie;
}

int DTInmueble::getAnioConstruccion() {
    return anioConstruccion;
}