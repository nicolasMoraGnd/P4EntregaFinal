#ifndef ISISTEMACONTROLLER_H
#define ISISTEMACONTROLLER_H

#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include <set>
#include <string>

class DTInmueble;
class DTInmuebleListado;
class DTPublicacion;

class ISistemaController {
public:
    virtual ~ISistemaController() {}

    // Caso de uso Alta Publicacion
    virtual bool altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio) = 0;

    // Caso de uso Consulta de Publicaciones
    virtual std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInm) = 0;
    virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) = 0;

    // Caso de uso Eliminar Inmueble
    virtual std::set<DTInmuebleListado*> listarInmuebles() = 0;
    virtual DTInmueble* detalleInmueble(int codigoInmueble) = 0;
    virtual void eliminarInmueble(int codigoInmueble) = 0;
};

#endif