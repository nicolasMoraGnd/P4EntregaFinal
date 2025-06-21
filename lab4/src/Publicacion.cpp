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
    AdministraPropiedad* adminProp = this->getAdministracionPropiedad();
    if(adminProp == NULL)
        return false;
    std::set<Publicacion*> publicacionesHermanas = adminProp->getPublicaciones();
    for(std::set<Publicacion*>::const_iterator it = publicacionesHermanas.begin(); it != publicacionesHermanas.end(); ++it){
        Publicacion* otraPub = *it;
        if(otraPub->getTipo() == this->getTipo() && this->getFecha() < otraPub->getFecha())
            return false;
    }
    return true;
}

float Publicacion::getPrecio() const {
    return this->precio;
}

AdministraPropiedad* Publicacion::getAdministracionPropiedad() const {
    return this->administracionPropiedadPadre;
}

std::string Publicacion::getNombreInmobiliaria() const {
    return this->administracionPropiedadPadre->getInmobiliariaAdmin()->getNombre();
}

DTPublicacion* Publicacion::getDTPublicacion() const {
    return new DTPublicacion(this->codigo, this->fecha, this->texto, this->precio, this->getNombreInmobiliaria());
}