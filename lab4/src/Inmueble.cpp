#include "../include/Inmueble.h"
#include "../include/Propietario.h"
#include "../include/AdministraPropiedad.h"

Inmueble::Inmueble(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* dueno)
    : codigo(codigo), direccion(direccion), numeroPuerta(numeroPuerta), superficie(superficie), anioConstruccion(anioConstruccion), propietarioDuenio(dueno) {}

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
    // TODO: Implementar la logica de busqueda en el set 'administraciones'
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
    // TODO
    administraciones.clear();
}

Inmueble::~Inmueble() {

}
