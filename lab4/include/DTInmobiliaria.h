#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <string> 

class DTInmobiliaria {
private:
    std::string direccion;
    std::string nickname;

public:

    DTInmobiliaria(std::string direccion, std::string nickname);


    std::string getDireccion() const;
    std::string getNickname() const;


    ~DTInmobiliaria();
};

#endif