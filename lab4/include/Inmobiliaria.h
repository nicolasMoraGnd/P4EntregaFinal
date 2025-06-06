#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include <string>
#include <set>

class Propietario;
class AdministraPropiedad;
class Inmueble;
struct DTUsuario;
struct DTFecha;
struct DTInmuebleListado;
// struct DTInmuebleAdministrado; Para listarInmueblesAdministrados

class Inmobiliaria : public Usuario {
private:
    std::string direccionFisica;
    std::string url;
    std::string telefonoInmobiliaria;

    std::set<Propietario*> propietariosRepresentados;
    std::set<AdministraPropiedad*> propiedadesAdministradas;

public:
    Inmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& dirFisica, const std::string& url, const std::string& telInmo);
    virtual ~Inmobiliaria();

    std::string getDireccionFisica() const;
    std::string getUrl() const;
    std::string getTelefonoInmobiliaria() const;

    DTUsuario* getDTUsuario() const; // Sobrescribe Usuario::getDTUsuario

    void agregarPropietarioRepresentado(Propietario* prop); // altaUsuario -> representarPropietario
    std::set<Propietario*> getPropietariosRepresentados() const;

    void agregarAdministracion(AdministraPropiedad* adminProp);
    std::set<AdministraPropiedad*> getPropiedadesAdministradas() const;

    // Métodos de "Alta de Administración de Propiedad"
    std::set<DTInmuebleListado*> getInmueblesNoAdminDePropietariosRepresentados() const;
    void altaAdministracionPropiedad(Inmueble* inmuebleAAdministrar, const DTFecha& fechaComienzo);

    // Métodos de "Alta de Publicación"
    // std::set<DTInmuebleAdministrado*> getDTInmueblesAdministrados() const; // Para listarInmueblesAdministrados
    // bool crearPublicacionParaInmueble(int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaActual, int& outCodigoPublicacion);
};

#endif