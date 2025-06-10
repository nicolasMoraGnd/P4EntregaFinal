#ifndef INMUEBLE_H
#define INMUEBLE_H

#include <string>

class Inmueble{
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;

    public:
        Inmueble(const int codigo, const std::string direccion, const int numeroPuerta, const int superficie, const int anoConstruccion);
        
        //getters
        int getCodigo() const;
        std::string getDireccion() const;
        int getnumeroPuerta() const;
        int getSuperficie() const;
        int getAnoConstruccion() const;

        //setters
        void setCodigo(const int& codigo);
        void setDireccion(const std::string& direccion);
        void setNumeroPuerta(const int& numeroPuerta);
        void setSuperficie(const int& superficie);
        void setAnoConstruccion(const int& anoConstruccion);

        //metodos
        virtual void desvincularInmueble() const = 0;
        virtual bool esCasa() const = 0; //no se le pasa nada a esCasa?

        //hast la vista bby
        virtual ~Inmueble();
};

#endif
