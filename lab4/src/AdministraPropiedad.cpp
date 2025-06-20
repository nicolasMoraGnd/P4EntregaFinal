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
    
}

/* Funciones redundantes/duplicadas o que no corresponden a esta clase y fueron hechas en otra parte

Ademas de que son la misma funcion, esto ya es lo mismo que Inmueble::esAdministradoPor

// veri
bool AdministraPropiedad::esDeInmobiliaria(const Inmobiliaria* inm) const {
    return inmobiliaria == inm;
}

bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria* inm) const {
    return inmobiliaria == inm;
}

No se supone que gestione memoria, para eso estan los controladores, y esto corresponde al caso de uso de altaPublicacion, no va aca
Segun el diagrama, SistemaController es quien hace el new, la responsabilidad de AdministraPropiedad es recibir y gestionar el objeto, no crearlo

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

Esto debe de pasar al momento de que se agregue una publicacion, si bien podemos utilizarlo como funcion auxiliar, no es necesario

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

Esto es un destructor, se puso en el destructor

// liberar publicaciones si hay ownership (si se crean acá) que no tengo idea
void AdministraPropiedad::eliminarPublicaciones() {
    std::set<Publicacion*>::iterator it;
    for (it = publicacionesAsociadas.begin(); it != publicacionesAsociadas.end(); ++it) {
        delete *it;
    }
    publicacionesAsociadas.clear();
}

Redundante y confunde responsabilidades, con Inmueble::desvincularInmueble ya estamos, te engaño el dcd

//metodos del dcd que tengo que ver los diagramas de comunicacion para verificar
void AdministraPropiedad::desvincularAdministrarPropiedadInmueble() {
    inmueble = NULL;
    inmobiliaria = NULL;
    eliminarPublicaciones();
}

Innecesario

//no tiene un get nombre pq no es un atributo
//de todas formas en publicacion hay un metodo que utiliza un get nombre
//habria que ver si agregarle el atributo o sustituirlo por otro identificador
std::string AdministraPropiedad::getNombreInmobiliaria() const {
    return inmobiliaria->getNombre();
}*/