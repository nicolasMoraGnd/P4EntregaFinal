#ifndef CASA_H
#define CASA_H

#include "Inmueble.h"
#include "TipoTecho.h"

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

    virtual bool esCasa() const;
    virtual void desvincularInmueble();
    virtual DTInmueble* getDTInmueble() const;
};

#endif