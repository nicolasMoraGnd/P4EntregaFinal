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
        Usuario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email);
        virtual ~Usuario();

        std::string getNickname() const;
        std::string getNombre() const;
        std::string getEmail() const;
        std::string getContrasena() const;

        virtual DTUsuario* getDTUsuario() const = 0;
};

#endif