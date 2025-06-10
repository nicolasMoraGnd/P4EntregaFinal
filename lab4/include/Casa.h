#ifndef CASA_H
#define CASA_H

#include "Inmueble.h"

enum tipoTecho {
    Liviano,
    ADosAguas,
    Plano
};

class Casa : public Inmueble{
    private:
      bool esPH;
      tipoTecho Techo;
    
    public:
        //bob el constructor (no es necesario el const aca solo en el string xd)
        Casa(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, tipoTecho techo);

        // metodo local(?
        bool esCasa() const;

        //Getters
        bool getEsPH() const;
        void setEsPH(bool esPH);

        //Setter
        tipoTecho getTipoTecho() const;
        void setTipoTecho(tipoTecho techo);

        //de inmueble coso pum
        void desvincularInmueble() const;

        // destructor de mundos
        virtual ~Casa();  

};

#endif