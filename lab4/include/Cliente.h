#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include <string>
#include <set>

class Cliente : public Usuario {
private:
    std::string apellido;
    std::string documento;

public:
    Cliente(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento);
    virtual ~Cliente();

    std::string getApellido() const;
    std::string getDocumento() const;

    void setApellido(const std::string& apellido);
    void setDocumento(const std::string& documento);
};

#endif