#ifndef PUBLICACION_H
#define PUBLICACION_H

#include "DTFecha.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include <string>

class AdministraPropiedad;
struct DTPublicacion;
 
class Publicacion {
private:
    int codigo;
    DTFecha& fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;

    AdministraPropiedad* administracionPropiedadPadre;

public:
    Publicacion(int codigo, const DTFecha& fecha, TipoPublicacion tipo, const std::string& texto, float precio, AdministraPropiedad* adminProp);
    ~Publicacion();

    int getCodigo() const;
    DTFecha getFecha() const;
    TipoPublicacion getTipo() const;
    bool esActiva() const; 
    AdministraPropiedad* getAdministracionPropiedad() const;

    void setActiva(bool estado);

    std::string getNombreInmobiliaria();
    DTPublicacion* getDTPublicacion() const;
};

#endif