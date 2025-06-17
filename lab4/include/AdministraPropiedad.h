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

        void agregarPublicacion(Publicacion* pub);
        bool existePublicacionReciente(const DTFecha& fecha, TipoPublicacion tipo) const;

        /*//verificacion
        bool esDeInmobiliaria(const Inmobiliaria* inm) const;

        //metodos funcionales relacionados a publicacion
        Publicacion* crearPublicacion(int codigoPub, TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaPub);
        
        //es necesario que exista pq una misma propiedad puede tener varias publicaciones a lo largo del tiempo,
        // pero solo una de ellas puede estar activa al mismo tiempo
        void actualizarEstadoActivaPublicaciones(Publicacion* nuevaPublicacion);

        // Métodos del DCD
        void desvincularAdministrarPropiedadInmueble();
        std::string getNombreInmobiliaria() const;
        bool inmobiliariaAsociada(Inmobiliaria* i) const;

        // Limpieza
        void eliminarPublicaciones();*/
};

#endif