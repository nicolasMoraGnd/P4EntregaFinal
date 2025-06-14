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
        Inmueble* inmueble;
        Inmobiliaria* inmobiliaria;
        DTFecha* fecha;
        Publicacion* publicacionAsociada; // ESTA ES LA RELACIÓN ASOCIATIVA

    public:
        AdministraPropiedad(Inmobiliaria* inmo, Inmueble* inm, const DTFecha& fechaIni);
        ~AdministraPropiedad(); // Gestiona la eliminación de Publicaciones que posee
        
        //getters
        DTFecha getFechaComienzo() const;
        Inmobiliaria* getInmobiliariaAdmin() const;
        Inmueble* getInmuebleAdministrado() const;
        std::set<Publicacion*> getPublicaciones() const;

        //verificacion
        bool esDeInmobiliaria(const Inmobiliaria* inm) const;

        //metodos funcionales
        Publicacion* crearPublicacion(int codigoPub, TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaPub);
        void agregarPublicacionGenerada(Publicacion* pub);
        void actualizarEstadoActivaPublicaciones(Publicacion* nuevaPublicacion);

        // Limpieza
         void eliminarPublicaciones();
};

#endif