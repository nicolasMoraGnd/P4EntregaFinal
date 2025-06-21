#include "../include/Inmueble.h"
#include "../include/Propietario.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Inmobiliaria.h"

Inmueble::Inmueble(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* dueno)
    : codigo(codigo), direccion(direccion), numeroPuerta(numeroPuerta), superficie(superficie), anioConstruccion(anioConstruccion), propietarioDuenio(dueno) {}

Inmueble::~Inmueble() {}

int Inmueble::getCodigo() const {
    return codigo;
}

std::string Inmueble::getDireccion() const {
    return direccion;
}

int Inmueble::getNumeroPuerta() const {
    return numeroPuerta;
}

int Inmueble::getSuperficie() const {
    return superficie;
}

int Inmueble::getAnioConstruccion() const {
    return anioConstruccion;
}

Propietario* Inmueble::getPropietarioDuenio() const {
    return propietarioDuenio;
}

void Inmueble::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Inmueble::setDireccion(const std::string& direccion) {
    this->direccion = direccion;
}

void Inmueble::setNumeroPuerta(int numeroPuerta) {
    this->numeroPuerta = numeroPuerta;
}

void Inmueble::setSuperficie(int superficie) {
    this->superficie = superficie;
}

void Inmueble::setAnioConstruccion(int anioConstruccion) {
    this->anioConstruccion = anioConstruccion;
}

bool Inmueble::esAdministradoPor(const Inmobiliaria* inm) const {
    for (std::set<AdministraPropiedad*>::const_iterator it = administraciones.begin(); it != administraciones.end(); ++it)
        if ((*it)->getInmobiliariaAdmin() == inm)
            return true;
    return false;
}

void Inmueble::asociarAdministracionPropiedad(AdministraPropiedad* adminProp) {
    administraciones.insert(adminProp);
}

void Inmueble::desasociarAdministracionPropiedad(AdministraPropiedad* adminProp) {
    administraciones.erase(adminProp);
}

std::set<AdministraPropiedad*> Inmueble::getAdministraciones() const {
    return administraciones;
}

void Inmueble::limpiarReferenciasAdministraciones() {
    administraciones.clear();
}

/*void Inmueble::desvincularInmueble() {
    if (this->propietarioDuenio != 0)
        this->propietarioDuenio->desvincularPropietarioInmueble(this);
    std::set<AdministraPropiedad*> administracionesACopiar = this->getAdministraciones();
    for (std::set<AdministraPropiedad*>::iterator it = administracionesACopiar.begin(); it != administracionesACopiar.end(); ++it) {
        AdministraPropiedad* admin = *it;
        if (admin->getInmobiliariaAdmin() != 0)
            admin->getInmobiliariaAdmin()->desvincularAdministracion(admin);
        delete admin;
    }
    this->limpiarReferenciasAdministraciones();
}
