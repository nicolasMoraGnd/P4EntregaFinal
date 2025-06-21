#ifndef SISTEMACONTROLLER_H
#define SISTEMACONTROLLER_H

#include "ISistemaController.h"

class SistemaController : public ISistemaController {
private:
    static SistemaController* instancia;
    SistemaController();

public:
    static SistemaController* getInstancia();
    ~SistemaController();

    virtual bool altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio);

    virtual std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInm);
    virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion);
    
    virtual std::set<DTInmuebleListado*> listarInmuebles();
    virtual DTInmueble* detalleInmueble(int codigoInmueble);
    virtual void eliminarInmueble(int codigoInmueble);
};

#endif