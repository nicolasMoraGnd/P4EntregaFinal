#include "../include/UsuarioHandler.h"
#include <cstddef>

UsuarioHandler* UsuarioHandler::instancia = 0;

UsuarioHandler::~UsuarioHandler(){}

UsuarioHandler::~UsuarioHandler(){
    for(std::map<std::string, Cliente*>::iterator it = mapClientes.begin(); it != mapClientes.end(); ++it)
        delete it->second;
    mapClientes.clear();
    for(std::map<std::string, Propietario*>::iterator it = mapPropietarios.begin(); it != mapPropietarios.end(); ++it)
        delete it->second;
    mapPropietarios.clear();
    for(std::map<std::string, Inmobiliaria*>::iterator it = mapInmobiliarias.begin(); it != mapInmobiliarias.end(); ++it)
        delete it->second;
    mapInmobiliarias.clear();
}

UsuarioHandler* UsuarioHandler::getInstancia(){
    if(instancia == NULL)
        instancia = new UsuarioHandler();
    return instancia;
}

void UsuarioHandler::agregarCliente(Cliente* cliente) {
    if(cliente != NULL)
        mapClientes[cliente->getNickname()] = cliente;
}

void UsuarioHandler::agregarPropietario(Propietario* propietario) {
    if(propietario != NULL)
        mapPropietarios[propietario->getNickname()] = propietario;
}

void UsuarioHandler::agregarInmobiliaria(Inmobiliaria* inmobiliaria) {
    if (inmobiliaria != NULL)
        mapInmobiliarias[inmobiliaria->getNickname()] = inmobiliaria;
}

bool UsuarioHandler::existeUsuario(std::string nickname){
    return (mapClientes.find(nickname) != mapClientes.end() ||
        mapPropietarios.find(nickname) != mapPropietarios.end() ||
        mapInmobiliarias.find(nickname) != mapInmobiliarias.end());
}

Inmobiliaria* UsuarioHandler::findInmobiliaria(std::string nickname) {
    std::map<std::string, Inmobiliaria*>::iterator it = mapInmobiliarias.find(nickname);
    if (it != mapInmobiliarias.end())
        return it->second;
    return NULL;
} 