#include "Apartamento.h"

// bobsisho el constructorrr
Apartamento::Apartamento(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion, float gastosComunes, int piso, bool tieneAscensor)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion), gastosComunes(gastosComunes), piso(piso), tieneAscensor(tieneAscensor) {}

//siempre retorna falseish o eso dice el DCD
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

// Setters
void Apartamento::setGastosComunes(float gastosComunes) {
    this->gastosComunes = gastosComunes;
}

void Apartamento::setPiso(int piso) {
    this->piso = piso;
}

void Apartamento::setTieneAscensor(bool tieneAscensor) {
    this->tieneAscensor = tieneAscensor;
}

// Implementación de método virtual puro
void Apartamento::desvincularInmueble() const {
    //ver que necesita para que se desvincule
}

//destructor de mundos
Apartamento::~Apartamento() {}


