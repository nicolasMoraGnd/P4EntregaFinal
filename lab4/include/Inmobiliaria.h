#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "IObserver.h"
#include "DTFecha.h"
#include <string>
#include <set>
#include <map>

//foward declarations
class Propietario;
class AdministraPropiedad;
class Inmueble;
class DTNotificacion;
struct DTUsuario;
struct DTInmuebleListado;
<<<<<<< HEAD
struct DTNotificacion; //para uso de los metodos con el observer
// struct DTInmuebleAdministrado; Para listarInmueblesAdministrados
=======
>>>>>>> main

// Inmobiliaria hereda de Usuario y es Observer de otra clase (no Inmueble)
// La asociación entre Inmobiliaria e Inmueble se modela a través de la clase asociativa AdministraPropiedad,
// que se encarga de administrar los inmuebles gestionados por la inmobiliaria.

class Inmobiliaria : public Usuario {
private:
    std::string direccionFisica;
    std::string url;
    std::string telefonoInmobiliaria;
    std::set<Propietario*> propietariosRepresentados;
    std::set<AdministraPropiedad*> propiedadesAdministradas;
    std::set<IObserver*> suscriptores;    

public:
    //constructor y destructor
    Inmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& dirFisica, const std::string& url, const std::string& telInmo);
    virtual ~Inmobiliaria();

    // Getters
    std::string getDireccionFisica() const;
    std::string getUrl() const;
    std::string getTelefonoInmobiliaria() const;
    DTUsuario* getDTUsuario() const; // Sobrescribe Usuario::getDTUsuario

    // Gestion de relaciones
    void agregarPropietarioRepresentado(Propietario* prop); // altaUsuario -> representarPropietario
    void agregarAdministracion(AdministraPropiedad* adminProp);
    void desvincularAdministracion(AdministraPropiedad* adminProp);
    std::set<AdministraPropiedad*> getPropiedadesAdministradas() const;
    std::set<Propietario*> getPropietariosRepresentados() const;  

    // Metodos de casos de uso
    std::set<DTInmuebleListado*> getInmueblesNoAdminPropietario() const;
    AdministraPropiedad* getAdministracionDeInmueble(int codigoInmueble) const;
    void altaAdministracionPropiedad(Inmueble* inmuebleAAdministrar, const DTFecha& fechaComienzo);

    // Metodos patron observer
    void suscribir(IObserver* obs);
    void desuscribir(IObserver* obs);
    void notificarSuscriptores(const DTNotificacion& notif);  
};

#endif