#include "../include/DTInmobiliaria.h"

DTInmobiliaria::DTInmobiliaria(std::string direccion, std::string nickname) {
    this->direccion = direccion;
    this->nickname = nickname;


}
std::string DTInmobiliaria::getDireccion() const {
    return this->direccion; 
}

std::string DTInmobiliaria::getNickname() const {
    return this->nickname;
}


DTInmobiliaria::~DTInmobiliaria() {
    // No hay memoria dinámica que liberar
}