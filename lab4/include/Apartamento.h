#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Inmueble.h"

class Apartamento : public Inmueble{
    private:
      float gastosComunes;
      int piso;
      bool tieneAscensor;
    
    public:
        //bob el constructor (no es necesario el const aca solo en el string xd)
        Apartamento(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion, float gastosComunes, int piso, bool tieneAscensor);

        // metodo local(?
        bool esCasa() const;

        //Getters
        float getGastosComunes() const;
        int getPiso() const;
        bool getTieneAscensor() const;

        //Setter
        void setGastosComunes(float gastosComunes);
        void setPiso(int piso);
        void setTieneAscensor(bool tieneAscensor);

        //de inmueble coso pum
        void desvincularInmueble() const;

        // Destructor
        virtual ~Apartamento();  

};

#endif