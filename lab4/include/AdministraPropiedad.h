#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H

#include "DTFecha.h"
#include "DTInmuebleAdministrado.h"
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
        DTFecha fecha; //es mucho mas eficiente para el trabajo (hacerlo puntero es medio al pepe)
        std::set<Publicacion*> publicacionesAsociadas; // ESTA ES LA RELACIÓN ASOCIATIVA

    public:
        AdministraPropiedad(Inmobiliaria* inmo, Inmueble* inm, const DTFecha& fechaIni);
        ~AdministraPropiedad(); // Gestiona la eliminación de Publicaciones que posee
        
        //getters
        DTFecha getFechaComienzo() const;
        Inmobiliaria* getInmobiliariaAdmin() const;
        Inmueble* getInmuebleAdministrado() const;
        std::set<Publicacion*> getPublicaciones() const;
        DTInmuebleAdministrado* getDTInmuebleAdministrado() const;

<<<<<<< HEAD
        //verificacion
=======
        void agregarPublicacion(Publicacion* pub);
        bool existePublicacionReciente(const DTFecha& fecha, TipoPublicacion tipo) const;

        /*//verificacion
>>>>>>> main
        bool esDeInmobiliaria(const Inmobiliaria* inm) const;

        //metodos funcionales relacionados a publicacion
        Publicacion* crearPublicacion(int codigoPub, TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaPub);
<<<<<<< HEAD
        void agregarPublicacionGenerada(Publicacion* pub);
        //es necesario que exista pq una misma propiedad puede tener varias publicaciones a lo largo del tiempo,
        // pero solo una de ellas puede estar activa al mismo tiempo
        void actualizarEstadoActivaPublicaciones(Publicacion* nuevaPublicacion);
        void eliminarPublicaciones();
=======
        
        //es necesario que exista pq una misma propiedad puede tener varias publicaciones a lo largo del tiempo,
        // pero solo una de ellas puede estar activa al mismo tiempo
        void actualizarEstadoActivaPublicaciones(Publicacion* nuevaPublicacion);
>>>>>>> main

        // Métodos del DCD
        void desvincularAdministrarPropiedadInmueble();
        std::string getNombreInmobiliaria() const;
        bool inmobiliariaAsociada(Inmobiliaria* i) const;

        // Limpieza
<<<<<<< HEAD
         void eliminarPublicaciones();
=======
        void eliminarPublicaciones();*/
>>>>>>> main
};

#endif