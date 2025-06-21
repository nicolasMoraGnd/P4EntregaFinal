#include "../include/AdministraPropiedad.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Publicacion.h"
#include "../include/DTFecha.h"

#include <algorithm> // por si se usa std::find o similares esto ta bueno pal futuro

AdministraPropiedad::AdministraPropiedad(Inmobiliaria* inmo, Inmueble* inm, const DTFecha& fechaIni)
    : inmobiliaria(inmo),
     inmueble(inm), 
     fecha(fechaIni) {
    // el set se inicializa solo
}

AdministraPropiedad::~AdministraPropiedad() {
    for (std::set<Publicacion*>::iterator it = this->publicacionesAsociadas.begin(); it != this->publicacionesAsociadas.end(); ++it)
        delete *it;
    this->publicacionesAsociadas.clear();
}

DTFecha AdministraPropiedad::getFechaComienzo() const {
    return fecha;
}

Inmobiliaria* AdministraPropiedad::getInmobiliariaAdmin() const {
    return inmobiliaria;
}

Inmueble* AdministraPropiedad::getInmuebleAdministrado() const {
    return inmueble;
}

std::set<Publicacion*> AdministraPropiedad::getPublicaciones() const {
    return publicacionesAsociadas;
}

DTInmuebleAdministrado* AdministraPropiedad::getDTInmuebleAdministrado() const{
    Inmueble* inm = this->getInmuebleAdministrado();
    return new DTInmuebleAdministrado(inm->getCodigo(), inm->getDireccion(), this->getFechaComienzo());
}

// Leer bien que tiene que hacer esto, particularmente que publicacion queda activa una vez se agrega.
void AdministraPropiedad::agregarPublicacion(Publicacion* pub) {
    publicacionesAsociadas.insert(pub);
}

bool AdministraPropiedad::existePublicacionReciente(const DTFecha& fechaActual, TipoPublicacion tipo) const {
    for (std::set<Publicacion*>::iterator it = this->publicacionesAsociadas.begin(); it != this->publicacionesAsociadas.end(); ++it){
        if(it->tipo == tipo && it->fecha == &fechaActual){
            return true
        }
    }
    return false
}

