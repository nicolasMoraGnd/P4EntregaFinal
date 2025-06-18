#include "../include/Apartamento.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/DTApartamento.h"

Apartamento::Apartamento(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion, Propietario* dueno, float gastosComunes, int piso, bool tieneAscensor)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion, dueno), gastosComunes(gastosComunes), piso(piso), tieneAscensor(tieneAscensor) {}

bool Apartamento::esCasa() const {
    return false;
}

float Apartamento::getGastosComunes() const {
    return gastosComunes;
}

int Apartamento::getPiso() const {
    return piso;
}

bool Apartamento::getTieneAscensor() const {
    return tieneAscensor;
}

void Apartamento::setGastosComunes(float gastosComunes) {
    this->gastosComunes = gastosComunes;
}

void Apartamento::setPiso(int piso) {
    this->piso = piso;
}

void Apartamento::setTieneAscensor(bool tieneAscensor) {
    this->tieneAscensor = tieneAscensor;
}

DTInmueble* Apartamento::getDTInmueble() const {
    return new DTApartamento(this->getCodigo(), this->getDireccion(), this->getNumeroPuerta(), this->getSuperficie(), this->getAnioConstruccion(), this->getPiso(), this->getTieneAscensor(), this->getGastosComunes());
}

Apartamento::~Apartamento() {}
