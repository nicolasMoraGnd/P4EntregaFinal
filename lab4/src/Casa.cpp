#include "Casa.h"

// bobsisho el constructorrr
Casa::Casa(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, tipoTecho techo)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion), esPH(esPH), Techo(techo) {}

//siempre retorna trueISH o eso dice el DCD
bool Casa::esCasa() const {
    return true;
}

//Getters
bool Casa::getEsPH() const {
    return esPH;
}

tipoTecho Casa::getTipoTecho() const {
    return Techo;
}

//Setters
void Casa::setEsPH(bool esPH) {
    this->esPH = esPH;
}

void Casa::setTipoTecho(tipoTecho techo) {
    this->Techo = techo;
}

// Implementación de método virtual puro
void Casa::desvincularInmueble() const {
    //ver que necesita para que se desvincule
}

//destructor de mundos
Casa::~Casa() {}


