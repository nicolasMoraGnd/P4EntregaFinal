#include "../include/Casa.h"
#include "../include/Propietario.h"
#include "../include/DTCasa.h"

Casa::Casa(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* dueno, bool esPH, TipoTecho tipoT)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion, dueno), esPH(esPH), techo(tipoT) {}

Casa::~Casa() {}

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

DTInmueble* Casa::getDTInmueble() const {
    return new DTCasa(this->getCodigo(), this->getDireccion(), this->getNumeroPuerta(), this->getSuperficie(), this->getAnioConstruccion(), this->getEsPH(), this->getTecho());
}

DTNotificacion Casa::crearDTNotificacion(const std::string& nickInmo, const std::string& texto, TipoPublicacion tipo) const {
    return DTNotificacion(nickInmo, this->getCodigo(), texto, tipo, true);
}