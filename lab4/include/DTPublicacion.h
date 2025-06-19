#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include "DTFecha.h"
#include <string>

class DTPublicacion {
    private:
        int codigo;
        DTFecha fecha;
        std::string texto;
        float precio;
        std::string inmobiliaria;

    public:
        DTPublicacion(int codigo, const DTFecha& fecha, const std::string& texto, float precio, const std::string& inmobiliaria);
        ~DTPublicacion();
        
        int getCodigo();
        DTFecha getFecha();
        std::string getTexto();
        float getPrecio();
        std::string getInmobiliaria();
};

#endif