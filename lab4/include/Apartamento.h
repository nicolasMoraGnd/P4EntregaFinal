#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"

class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        Apartamento(int cod, const std::string& dir, int nroP, int sup, int anioC, Propietario* duen, int p, bool asc, float gc);
        virtual ~Apartamento(); 
        int getPiso() const;
        bool getTieneAscensor() const;
        float getGastosComunes() const;

        virtual DTInmueble* getDTInmueble() const;
};

#endif