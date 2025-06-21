#include "../include/UsuarioHandler.h"
#include <cstddef>

UsuarioHandler* UsuarioHandler::instancia = 0;

UsuarioHandler::UsuarioHandler(){}

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

Inmobiliaria* UsuarioHandler::findInmobiliaria(const std::string& nickname) const {
    std::map<std::string, Inmobiliaria*>::const_iterator it = mapInmobiliarias.find(nickname);
    if (it != mapInmobiliarias.end())
        return it->second;
    return NULL;
} 

Usuario* UsuarioHandler::findUsuario(const std::string& nickname) const {
    std::map<std::string, Cliente*>::const_iterator itCli = this->mapClientes.find(nickname);
    if (itCli != this->mapClientes.end())
        return itCli->second;

    std::map<std::string, Propietario*>::const_iterator itProp = this->mapPropietarios.find(nickname);
    if (itProp != this->mapPropietarios.end())
        return itProp->second;

    std::map<std::string, Inmobiliaria*>::const_iterator itInmo = this->mapInmobiliarias.find(nickname);
    if (itInmo != this->mapInmobiliarias.end())
        return itInmo->second;

    return NULL;
}

std::set<DTUsuario*> UsuarioHandler::listarPropietarios() const {
    std::set<DTUsuario*> resultado;
    for (std::map<std::string, Propietario*>::const_iterator it = this->mapPropietarios.begin(); it != this->mapPropietarios.end(); ++it)
        resultado.insert(it->second->getDTUsuario());
    return resultado;
}

std::map<std::string, Inmobiliaria*> UsuarioHandler::getInmobiliarias(){
    return this->mapInmobiliarias;
}