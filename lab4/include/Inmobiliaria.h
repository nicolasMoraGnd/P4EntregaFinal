#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include <string>
#include <set>
#include <map>

class Propietario;
class AdministraPropiedad;
class Inmueble;
struct DTUsuario;
struct DTFecha;
struct DTInmuebleListado;
// struct DTInmuebleAdministrado; Para listarInmueblesAdministrados

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

    //relacion inmobiliarias inmueble
    int key;
    std::map<int, Inmueble*> inmuebles;
    

public:
    Inmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& dirFisica, const std::string& url, const std::string& telInmo);
    virtual ~Inmobiliaria();

    //getters
    std::string getDireccionFisica() const;
    std::string getUrl() const;
    std::string getTelefonoInmobiliaria() const;
    DTUsuario* getDTUsuario() const; // Sobrescribe Usuario::getDTUsuario

    //propietarios
    void agregarPropietarioRepresentado(Propietario* prop); // altaUsuario -> representarPropietario
    void desvincularAdministracion(AdministraPropiedad* adminProp);
    std::set<Propietario*> getPropietariosRepresentados() const;

    //administraciones
    void agregarAdministracion(AdministraPropiedad* adminProp);
    std::set<AdministraPropiedad*> getPropiedadesAdministradas() const;

    //asociaciones con inmuebles
    void asociarInmueble(int codigo, Inmueble* inmueble);
    void desasociarInmueble(int codigo);
    std::map<int, Inmueble*> getInmuebles() const;

    // Métodos de "Alta de Administración de Propiedad"
    std::set<DTInmuebleListado*> getInmueblesNoAdminDePropietariosRepresentados() const;
    void altaAdministracionPropiedad(Inmueble* inmuebleAAdministrar, const DTFecha& fechaComienzo);

    // Métodos de "Alta de Publicación"
    // std::set<DTInmuebleAdministrado*> getDTInmueblesAdministrados() const; // Para listarInmueblesAdministrados
    // bool crearPublicacionParaInmueble(int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaActual, int& outCodigoPublicacion);
};

#endif