#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Inmueble.h"
#include "../include/IObserver.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTNotificacion.h"
#include "../include/DTUsuario.h"

// Constructor
Inmobiliaria::Inmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre,
                           const std::string& email, const std::string& dirFisica, const std::string& url, const std::string& telInmo)
    : Usuario(nickname, contrasena, nombre, email),
      direccionFisica(dirFisica),
      url(url),
      telefonoInmobiliaria(telInmo)
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

std::set<DTInmuebleListado*> Inmobiliaria::getInmueblesNoAdminPropietario() const {
    std::set<DTInmuebleListado*> resultado;
    for(std::set<Propietario*>::const_iterator it = propietariosRepresentados.begin(); it != propietariosRepresentados.end(); ++it){
        Propietario* prop = *it;
        std::set<DTInmuebleListado*> listInmueblesProp = prop->getInmueblesNoAdmin(this);
        for (std::set<DTInmuebleListado*>::const_iterator ite = listInmueblesProp.begin(); ite != listInmueblesProp.end(); ++ite)
            resultado.insert(*ite);
    }
    return resultado;
}

DTUsuario* Inmobiliaria::getDTUsuario() const {
    return new DTUsuario(getNickname(), getNombre());
}

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* inmuebleAAdministrar, const DTFecha& fechaComienzo) {
    AdministraPropiedad* nuevaAdmin = new AdministraPropiedad(this, inmuebleAAdministrar, fechaComienzo);
    this->agregarAdministracion(nuevaAdmin);
    inmuebleAAdministrar->asociarAdministracionPropiedad(nuevaAdmin);
}

Inmobiliaria::~Inmobiliaria() {
    for (std::set<AdministraPropiedad*>::iterator it = propiedadesAdministradas.begin(); it != propiedadesAdministradas.end(); ++it) {
        delete *it;
    }
    propiedadesAdministradas.clear();
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
        if (adminActual != 0 && adminActual->getInmuebleAdministrado() != 0 && adminActual->getInmuebleAdministrado()->getCodigo() == codigoInmueble)
            return adminActual;
    }
    return 0; // o NULL?
}

void Inmobiliaria::desvincularAdministracion(AdministraPropiedad* adminProp){
    this->propiedadesAdministradas.erase(adminProp);
}
