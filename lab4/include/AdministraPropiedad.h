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

        void agregarPublicacion(Publicacion* pub);
        bool existePublicacionReciente(const DTFecha& fecha, TipoPublicacion tipo) const;
};

#endif