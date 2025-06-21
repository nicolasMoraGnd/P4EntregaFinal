#ifndef PUBLICACION_H
#define PUBLICACION_H

#include "DTFecha.h"
#include "TipoPublicacion.h"
#include <string>

class AdministraPropiedad;
class DTPublicacion;
 
class Publicacion {
private:
    int codigo;
    DTFecha fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;

    AdministraPropiedad* administracionPropiedadPadre;

public:
    Publicacion(int codigo, const DTFecha& fecha, TipoPublicacion tipo, const std::string& texto, float precio, AdministraPropiedad* adminProp);
    ~Publicacion();

    int getCodigo() const;
    DTFecha getFecha() const;
    TipoPublicacion getTipo() const;
    float getPrecio() const;
    AdministraPropiedad* getAdministracionPropiedad() const;
    
    std::string getNombreInmobiliaria() const;
    DTPublicacion* getDTPublicacion() const;

    bool esActiva() const; 
};

#endif