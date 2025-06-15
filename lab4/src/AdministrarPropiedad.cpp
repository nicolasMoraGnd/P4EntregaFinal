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

// veri
bool AdministraPropiedad::esDeInmobiliaria(const Inmobiliaria* inm) const {
    return inmobiliaria == inm;
}

//AVER ACA DEPENDE DE LA GENTE QUE HACE PUBLICACIONES POR ESO LO DEJO EN STANDBY
// creacion de asociacion para luego asociarla
//esto es asumiendo los atributos de publicacion despues hay que ver si estan escritos iguales aunque en realidad no le hace
Publicacion* AdministraPropiedad::crearPublicacion(int codigoPub, TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaPub) {
   
    Publicacion* nueva = new Publicacion(codigoPub, tipo, texto, precio, fechaPub, this);
    actualizarEstadoActivaPublicaciones(nueva);
    publicacionesAsociadas.insert(nueva);
    return nueva;
}

//agregamos la publicacion al set
void AdministraPropiedad::agregarPublicacionGenerada(Publicacion* pub) {
    publicacionesAsociadas.insert(pub);
}

// Actualizar estado activo: por ejemplo, marcar una como activa y otras como inactivas
void AdministraPropiedad::actualizarEstadoActivaPublicaciones(Publicacion* nuevaPublicacion) {
    std::set<Publicacion*>::iterator it;
    for (it = publicacionesAsociadas.begin(); it != publicacionesAsociadas.end(); ++it) {
        Publicacion* pub = *it;
        if (pub == nuevaPublicacion) {
            pub->setActiva(true);
        } else {
            pub->setActiva(false);
        }
    }
}

// liberar publicaciones si hay ownership (si se crean acá) que no tengo idea
void AdministraPropiedad::eliminarPublicaciones() {
    std::set<Publicacion*>::iterator it;
    for (it = publicacionesAsociadas.begin(); it != publicacionesAsociadas.end(); ++it) {
        delete *it;
    }
    publicacionesAsociadas.clear();
}

//metodos del dcd que tengo que ver los diagramas de comunicacion para verificar
void AdministraPropiedad::desvincularAdministrarPropiedadInmueble() {
    inmueble = NULL;
    inmobiliaria = NULL;
    eliminarPublicaciones();
}

//no tiene un get nombre pq no es un atributo
//de todas formas en publicacion hay un metodo que utiliza un get nombre
//habria que ver si agregarle el atributo o sustituirlo por otro identificador
std::string AdministraPropiedad::getNombreInmobiliaria() const {
    return inmobiliaria->getNombre();
}

bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria* inm) const {
    return inmobiliaria == inm;
}

AdministraPropiedad::~AdministraPropiedad() {
    eliminarPublicaciones(); // Si esta clase tiene ownership
}