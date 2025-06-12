#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H

#include "DTFecha.h"
#include <set>
#include <string>

class Inmobiliaria;
class Inmueble;
class Publicacion;
enum TipoPublicacion; 

class AdministraPropiedad {
private:
    DTFecha* fechaComienzo;
    Inmobiliaria* inmobiliariaAsociada;
    Inmueble* inmuebleAsociado;
    std::set<Publicacion*> publicacionesGeneradas;

public:
    AdministraPropiedad(Inmobiliaria* inmo, Inmueble* inm, const DTFecha& fechaIni);
    ~AdministraPropiedad();

    DTFecha getFechaComienzo() const;
    Inmobiliaria* getInmobiliariaAdmin() const;
    Inmueble* getInmuebleAdministrado() const;
    std::set<Publicacion*> getPublicaciones() const;

    bool esDeInmobiliaria(const Inmobiliaria* inm) const;
    void crearPublicacion(TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaPub);
};

#endif