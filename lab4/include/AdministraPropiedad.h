#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H

#include "DTFecha.h"
#include <set>

class Inmobiliaria;
class Inmueble;
class Publicacion;
enum TipoPublicacion; 

class AdministraPropiedad {
    private:
        DTFecha* fecha;

    public:
        AdministraPropiedad(Inmobiliaria* inmo, Inmueble* inm, const DTFecha& fechaIni);
        ~AdministraPropiedad(); // Gestiona la eliminación de Publicaciones que posee

        DTFecha getFechaComienzo() const;
        Inmobiliaria* getInmobiliariaAdmin() const;
        Inmueble* getInmuebleAdministrado() const;
        std::set<Publicacion*> getPublicaciones() const;

        bool esDeInmobiliaria(const Inmobiliaria* inm) const;

        Publicacion* crearPublicacion(int codigoPub, TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaPub);
        void agregarPublicacionGenerada(Publicacion* pub);
        void actualizarEstadoActivaPublicaciones(Publicacion* nuevaPublicacion);

        void eliminarPublicaciones();
};

#endif