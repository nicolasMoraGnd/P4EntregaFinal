#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Inmueble.h"
#include "TipoPublicacion.h"

class Apartamento : public Inmueble {
private:
    int piso;
    bool tieneAscensor;
    float gastosComunes;

public:
    Apartamento(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* dueno, float gastosComunes, int piso, bool tieneAscensor);
    virtual ~Apartamento();

    int getPiso() const;
    bool getTieneAscensor() const;
    float getGastosComunes() const;

    void setPiso(int piso);
    void setTieneAscensor(bool tieneAscensor);
    void setGastosComunes(float gastosComunes);

    virtual DTInmueble* getDTInmueble() const;

    DTNotificacion crearDTNotificacion(const std::string& nickInmo, const std::string& texto, TipoPublicacion tipo) const;
};

#endif