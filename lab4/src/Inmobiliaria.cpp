#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Inmueble.h"
#include "IObserver.h"
#include "DTUsuario.h"
#include "DTFecha.h"
#include "DTInmuebleListado.h"
//#include "DTNotificacion.h" hay que imlementar este datatype

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

DTUsuario* Inmobiliaria::getDTUsuario() const {
    //Implementa la creación del DTUsuario correspondiente asi que pendiente
    return new DTUsuario(/* pasar datos relevantes */);
    // return NULL; es otra opcion
}

//management de los propietarios
void Inmobiliaria::agregarPropietarioRepresentado(Propietario* prop) {
    propietariosRepresentados.insert(prop);
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

void Inmobiliaria::desvincularAdministracion(AdministraPropiedad* adminProp) {
    propiedadesAdministradas.erase(adminProp);
}

//asociacion con inmueeeeebles
void Inmobiliaria::asociarInmueble(int key, Inmueble* inmueble) {
    inmuebles[key] = inmueble;
}

void Inmobiliaria::desasociarInmueble(int key) {
    inmuebles.erase(key);
}

std::map<int, Inmueble*> Inmobiliaria::getInmuebles() const {
    return inmuebles;
}


//SACADO DE CHATGPT FALTA VER DCD Y TEORICO PARA QUE CURTA BIEN Y RAYE ZARPADO
// métodos relacionados a "Alta de Administración de Propiedad"
std::set<DTInmuebleListado*> Inmobiliaria::getInmueblesNoAdminDePropietariosRepresentados() const {
    // Aquí implementas la lógica que filtre y devuelva un set de inmuebles listados que no están administrados
    // por la inmobiliaria y pertenecen a propietarios representados.
    std::set<DTInmuebleListado*> resultado;

    // Ejemplo (pseudo-código):
    // Por cada propietarioRepresentado
    //    por cada inmueble del propietario
    //       si inmueble no está administrado por esta inmobiliaria
    //          agregar a resultado

    return resultado;
}

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* inmuebleAAdministrar, const DTFecha& fechaComienzo) {
    // Crear nuevo AdministraPropiedad asociando inmobiliaria e inmueble
    AdministraPropiedad* nuevaAdmin = new AdministraPropiedad(this, inmuebleAAdministrar, fechaComienzo);
    
    // Agregar a propiedades administradas
    agregarAdministracion(nuevaAdmin);

    // Asociar inmueble a inmobiliaria (opcional si ya se hace en AdministraPropiedad)
    asociarInmueble(inmuebleAAdministrar->getCodigo(), inmuebleAAdministrar);

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
