#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Inmueble.h"
#include "../include/IObserver.h"

// Constructor
Inmobiliaria::Inmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre,
                           const std::string& email, const std::string& dirFisica, const std::string& url, const std::string& telInmo)
    : Usuario(nickname, contrasena, nombre, email),
      direccionFisica(dirFisica),
      url(url),
      telefonoInmobiliaria(telInmo),
      key(0) //es inicializae en 0 el coso del map pero se puede cambiar
{
    // Inicializaciones si hacen falta
}

std::string Inmobiliaria::getDireccionFisica() const {
    return direccionFisica;
}

std::string Inmobiliaria::getUrl() const {
    return url;
}

std::string Inmobiliaria::getTelefonoInmobiliaria() const {
    return telefonoInmobiliaria;
}

//para los propietarios a ver
void Inmobiliaria::agregarPropietarioRepresentado(Propietario* prop) {
    this->propietariosRepresentados.insert(prop);
    prop->agregarInmobiliariaQueRepresenta(this);
}

std::set<Propietario*> Inmobiliaria::getPropietariosRepresentados() const {
    return propietariosRepresentados;
}

//metodos administrativos
void Inmobiliaria::agregarAdministracion(AdministraPropiedad* adminProp) {
    propiedadesAdministradas.insert(adminProp);
}

std::set<AdministraPropiedad*> Inmobiliaria::getPropiedadesAdministradas() const {
    return propiedadesAdministradas;
}

// IMPLEMENTAR POR FAVOR SUMAMENTE IMPORTANTE VER AdministracionPropiedad_SoloDiagramas_2025
std::set<DTInmuebleListado*> Inmobiliaria::getInmueblesNoAdminPropietario() const {
    std::set<DTInmuebleListado*> resultado;
    return resultado;
}

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* inmuebleAAdministrar, const DTFecha& fechaComienzo) {
    // Crear nuevo AdministraPropiedad asociando inmobiliaria e inmueble
    AdministraPropiedad* nuevaAdmin = new AdministraPropiedad(this, inmuebleAAdministrar, fechaComienzo);
    
    // Agregar a propiedades administradas
    this->agregarAdministracion(nuevaAdmin);

    // También deberías llamar a métodos de Inmueble para asociar esta administración,
    // si la clase inmueble tiene algo así:
    inmuebleAAdministrar->asociarAdministracionPropiedad(nuevaAdmin);
}

//metodos para la gestion de suscriptores
void Inmobiliaria::agregarSuscriptor(IObserver* observer) {
    suscriptores.insert(observer);
}
void Inmobiliaria::eliminarSuscriptor(IObserver* observer) {
    suscriptores.erase(observer);
}

void Inmobiliaria::notificarSuscriptores(DTNotificacion* notificacion) {
    for (std::set<IObserver*>::iterator it = suscriptores.begin(); it != suscriptores.end(); ++it) {
        (*it)->actualizar(notificacion);
    }
}

//metodos de alta publicacion
std::set<DTInmuebleListado*> Inmobiliaria::getDTInmueblesAdministrados() const {
    std::set<DTInmuebleListado*> resultado;
    return resultado;
}

Inmobiliaria::~Inmobiliaria() {
    // Liberar recursos si es necesario, pero como usamos punteros sin ownership
    // no borramos objetos referenciados aquí. Aunque podemos revisar que onda por una cosa que dijo la profe de memoria estatica
}

void Inmobiliaria::suscribir(IObserver* obs) {
    this->suscriptores.insert(obs);
}

void Inmobiliaria::desuscribir(IObserver* obs) {
    this->suscriptores.erase(obs);
}

void Inmobiliaria::notificarSuscriptores(const DTNotificacion& notif) {
    for (std::set<IObserver*>::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it) {
        IObserver* observador = *it;
        observador->notificar(notif);
    }
}

AdministraPropiedad* Inmobiliaria::getAdministracionDeInmueble(int codigoInmueble) const {
    for (std::set<AdministraPropiedad*>::const_iterator it = this->propiedadesAdministradas.begin(); it != this->propiedadesAdministradas.end(); ++it){
        AdministraPropiedad* adminActual = *it;
        if(adminActual != 0 && adminActual->getInmuebleAdministrado() != 0)
            if(adminActual->getInmuebleAdministrado()->getCodigo() == codigoInmueble)
                return adminActual;
    }
    return 0; // o NULL?
}
