#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

<<<<<<< HEAD
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
=======
#include "TipoPublicacion.h"
#include <string> 

class DTNotificacion {
    private:
        std::string nickInmo;
        int codigo;
        std::string texto;
        TipoPublicacion tipo;
        bool esCasa;

    public:
        DTNotificacion(const std::string& nickInmo, int codigo, const std::string& texto, TipoPublicacion tipo, bool esCasa);
        ~DTNotificacion();

        std::string getNickInmo() const;
        int getCodigo() const;
        std::string getTexto() const;
        TipoPublicacion getTipo() const;
        bool getEsCasa() const;
>>>>>>> main
};

#endif