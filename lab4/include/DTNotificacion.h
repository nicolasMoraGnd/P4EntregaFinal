#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string> 
#include "TipoPublicacion.h"


class DTNotificacion {
private:
    std::string nickInmo;
    int codigo;
    std::string texto;
    TipoPublicacion tipo;
    bool esCasa;

public:

    DTNotificacion(std::string nickInmo, int codigo, std::string texto, TipoPublicacion tipo, bool esCasa);


    std::string getNickInmo() const;
    int getCodigo() const;
    std::string getTexto() const;
    TipoPublicacion getTipo() const;
    bool getEsCasa() const;


    ~DTNotificacion();
};

#endif
//work de marcos