#include "Inmueble.h"

//bob el constructor
Inmueble::Inmueble(const int codigo, const std::string direccion, const int numeroPuerta, const int superfice, const int anoConstruccion)
    :codigo(codigo),
     direccion(direccion),
     numeroPuerta(numeroPuerta),
     superficie(superficie),
     anoConstruccion(anoConstruccion) {}


//Getters
int Inmueble::getCodigo() const {
    return codigo;
}

std::string Inmueble::getDireccion() const {
    return direccion;
}

int Inmueble::getnumeroPuerta() const {
    return numeroPuerta;
}

int Inmueble::getSuperficie() const {
    return superficie;
}

int Inmueble::getAnoConstruccion() const {
    return anoConstruccion;
}

// Setters
void Inmueble::setCodigo(const int& codigo) {
    this->codigo = codigo;
}

void Inmueble::setDireccion(const std::string& direccion) {
    this->direccion = direccion;
}

void Inmueble::setNumeroPuerta(const int& numeroPuerta) {
    this->numeroPuerta = numeroPuerta;
}

void Inmueble::setSuperficie(const int& superficie) {
    this->superficie = superficie;
}

void Inmueble::setAnoConstruccion(const int& anoConstruccion) {
    this->anoConstruccion = anoConstruccion;
}

//destructora de mundos que como por ahora no hay punteros dinamicos 
Inmueble::~Inmueble() {}