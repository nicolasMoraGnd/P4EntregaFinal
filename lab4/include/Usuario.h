#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario {
    private:
        std::string nickname;
        std::string contrasena;
        std::string nombre;
        std::string email;

    public:
        Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
        virtual ~Usuario();
        std::string getNickname() const;
        std::string getNombre() const;
        std::string getEmail() const;
        // getContrasena podria omitirse por seguridad o ser protected
        // Setters (considerar diseño)
        // void setContrasena(const std::string& contra); Si se permite cambiar
};

#endif