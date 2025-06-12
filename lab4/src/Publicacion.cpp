#include "../include/Publicacion.h"

Publicacion::Publicacion(int codigo, const DTFecha& fecha, TipoPublicacion tipo, const std::string& texto, float precio, AdministraPropiedad* adminProp)
    : codigo(codigo), 
    fecha(fecha), 
    tipo(tipo), 
    texto(texto), 
    precio(precio), 
    administracionPropiedadPadre(adminProp){};

int Publicacion::getCodigo() const {
    return codigo;
}
DTFecha Publicacion::getFecha() const {
    return fecha;
}
TipoPublicacion Publicacion::getTipo() const {
    return tipo;
}
bool Publicacion::esActiva() const {
    return activa;
}
AdministraPropiedad* Publicacion::getAdministracionPropiedad() const {
    return administracionPropiedadPadre;
}

void setActiva(bool estado){
    activa = estado;
}

DTPublicacion* Publicacion::getDTPublicacion() {
    return new DTPublicacion(codigo, fecha, texto, precio, adminProp->getInmobiliaria());
}