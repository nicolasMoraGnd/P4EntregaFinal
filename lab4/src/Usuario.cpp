#include "../include/Usuario.h"
#include <string>

Usuario::Usuario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email): nickname(nickname), contrasena(contrasena), nombre(nombre), email(email) {}

std::string Usuario::getNickname() const{
    return this->nickname;
}

 std::string Usuario::getNombre() const{
    return this->nombre;
 }

 std::string Usuario::getEmail() const{
    return this->email;
 }

 std::string Usuario::getContrasena() const{
    return this->contrasena;
 }

