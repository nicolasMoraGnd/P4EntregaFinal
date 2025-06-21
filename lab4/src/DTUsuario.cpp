#include "../include/DTUsuario.h"
#include <iostream>

DTUsuario::DTUsuario(std::string nickname, std::string nombre, std::string constrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

std::string DTUsuario::getNickname() {
    return nickname;
}

std::string DTUsuario::getNombre() {
    return nombre;
}

<<<<<<< HEAD
std::string DTUsuario::getContrasena() {
    return contrasena;
}

std::string DTUsuario::getEmail() {
    return email;
}

// Implementación del destructor
DTUsuario::~DTUsuario() {
    // No hay memoria dinámica que liberar
}

bool DTUsuario::operator<(DTUsuario& other) {
=======
bool DTUsuario::operator<<(DTUsuario& other) {
>>>>>>> main
    return nickname < other.nickname; // Comparar directamente los campo
}
