#include "../include/Casa.h"
#include "../include/DTInmueble.h"
#include "../include/Propietario.h"

Casa::Casa(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* duen, bool esPH, TipoTecho tipoT)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion, duen), esPH(esPH), techo(tipoT) {}

bool Casa::esCasa() const {
    return true;
}

bool Casa::getEsPH() const {
    return esPH;
}

TipoTecho Casa::getTecho() const {
    return techo;
}

void Casa::setEsPH(bool esPH) {
    this->esPH = esPH;
}

void Casa::setTecho(TipoTecho techo) {
    this->techo = techo;
}

void Casa::desvincularInmueble() {

}

DTInmueble* Casa::getDTInmueble() const {
    // TODO: Implementar la creación y retorno de un DTInmueble
    return 0;
}

Casa::~Casa() {}