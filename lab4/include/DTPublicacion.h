#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include "DTFecha.h"
#include <string>

class DTPublicacion {
    private:
        int codigo;
        DTFecha* fecha;
        std::string texto;
        TipoPublicacion tipo;
        float precio;
        std::string inmobiliaria;
        bool activa;

    public:
        DTPublicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo,std::string texto, float precio, std::string inmobiliaria, bool activa);
        int getCodigo();
        DTFecha* getFecha();
        std::string getTexto();
        float getPrecio();
        TipoPublicacion getTipoPublicacion();
        std::string getInmobiliaria();
        bool getActiva();
        ~DTPublicacion();
};

#endif