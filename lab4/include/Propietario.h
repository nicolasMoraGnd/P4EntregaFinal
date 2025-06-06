#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include "Usuario.h"
#include <string>
#include <set>


class Inmueble;
class Inmobiliaria; // Para el método getInmueblesNoAdminPorInmobiliaria
struct DTInmuebleListado;

class Propietario : public Usuario {
private:
    std::string cuentaBancaria;
    std::string telefono;
    std::set<Inmueble*> inmuebles;

public:
    Propietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono);
    virtual ~Propietario();

    std::string getCuentaBancaria() const;
    std::string getTelefono() const;

    void agregarInmueble(Inmueble* inm);
    void eliminarInmueble(Inmueble* inm);
    std::set<Inmueble*> getInmuebles() const;

    std::set<DTInmuebleListado*> getInmueblesNoAdminPorInmobiliaria(const Inmobiliaria* inm) const;

    // virtual DTUsuario* getDTUsuario() const; Sobrescribir si es necesario
};

#endif