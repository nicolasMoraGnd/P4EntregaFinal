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

//DTUsuario* Inmobiliaria::getDTUsuario() const {
    // Implementa la creación del DTUsuario correspondiente asi que pendiente
    //return new DTUsuario(/* pasar datos relevantes */);
//}

//para los propietarios a ver
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
