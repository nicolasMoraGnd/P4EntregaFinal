#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTPublicacion.h"

Publicacion::Publicacion(int codigo, const DTFecha& fecha, TipoPublicacion tipo, const std::string& texto, float precio, AdministraPropiedad* adminProp)
    : codigo(codigo), 
    fecha(fecha), 
    tipo(tipo), 
    texto(texto), 
    precio(precio), 
    activa(false),
    administracionPropiedadPadre(adminProp){};

Publicacion::~Publicacion() {}

int Publicacion::getCodigo() const {
    return this->codigo;
}
DTFecha Publicacion::getFecha() const {
    return this->fecha;
}
TipoPublicacion Publicacion::getTipo() const {
    return this->tipo;
}
bool Publicacion::esActiva() const {
    return this->activa;
}
AdministraPropiedad* Publicacion::getAdministracionPropiedad() const {
    return this->administracionPropiedadPadre;
}

void Publicacion::setActiva(bool estado){
    this->activa = estado;
}

std::string Publicacion::getNombreInmobiliaria() const {
    return this->administracionPropiedadPadre->getInmobiliariaAdmin()->getNombre();
}

DTPublicacion* Publicacion::getDTPublicacion() const {
    return new DTPublicacion(this->codigo, this->fecha, this->texto, this->precio, this->getNombreInmobiliaria());
}