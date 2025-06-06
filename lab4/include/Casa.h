#ifndef CASA_H
#define CASA_H
#include "Inmueble.h"
#include "TipoTecho.h"

class Casa : public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        Casa(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* duen, bool ph, TipoTecho tipoT);
        virtual ~Casa(); 
        bool getEsPH() const;
        TipoTecho getTecho() const;

        virtual DTInmueble* getDTInmueble() const;
};

#endif