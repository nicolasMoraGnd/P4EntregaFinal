#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H

#include "DTFecha.h"
#include <string>

class DTPublicacion {
    private:
        int codigo;
        DTFecha fecha;
        std::string texto;
<<<<<<< HEAD
        TipoPublicacion tipo;
=======
>>>>>>> main
        float precio;
        std::string inmobiliaria;
        bool activa;

    public:
<<<<<<< HEAD
        DTPublicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo,std::string texto, float precio, std::string inmobiliaria, bool activa);
        int getCodigo();
        DTFecha* getFecha();
        std::string getTexto();
        float getPrecio();
        TipoPublicacion getTipoPublicacion();
        std::string getInmobiliaria();
        bool getActiva();
=======
        DTPublicacion(int codigo, const DTFecha& fecha, const std::string& texto, float precio, const std::string& inmobiliaria);
>>>>>>> main
        ~DTPublicacion();
        
        int getCodigo();
        DTFecha getFecha();
        std::string getTexto();
        float getPrecio();
        std::string getInmobiliaria();
};

#endif