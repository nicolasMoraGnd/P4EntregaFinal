#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>

class DTUsuario {
    private:
        std::string nickname, nombre, contrasena, email;

    public:
        DTUsuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
        std::string getNickname();
        std::string getNombre();
        std::string getContrasena();
        std::string getEmail();
        bool operator<(DTUsuario& other);
};
#endif