#ifndef CASA_H
#define CASA_H

#include "Inmueble.h"
#include "TipoTecho.h"
#include "DTNotificacion.h"
#include "TipoPublicacion.h"

class Casa : public Inmueble {
private:
    bool esPH;
    TipoTecho techo;

public:
    Casa(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* dueno, bool esPH, TipoTecho tipoT);
    virtual ~Casa();

    bool getEsPH() const;
    TipoTecho getTecho() const;

    void setEsPH(bool esPH);
    void setTecho(TipoTecho techo);

    virtual DTInmueble* getDTInmueble() const;

    DTNotificacion crearDTNotificacion(const std::string& nickInmo, const std::string& texto, TipoPublicacion tipo) const;
};

#endif