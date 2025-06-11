#include "../include/UsuarioHandler.h"

UsuarioHandler* UsuarioHandler::getInstancia(){
    if(instancia== NULL){
        instancia = new UsuarioHandler();
    }
    return instancia
}

void UsuarioHandler::agregarCliente(Cliente* cliente) {
    mapClientes.insert(std::make_pair(cliente->getNickname(), cliente));
}

void UsuarioHandler::agregarPropietario(Propietario* propietario) {
    mapPropietarios.insert(std::make_pair(propietario->getNickname(), propietario));
}

void UsuarioHandler::agregarInmobiliaria(Inmobiliaria* inmobiliaria) {
    mapInmobiliarias.insert(std::make_pair(inmobiliaria->getNickname(), inmobiliaria));
}

bool UsuarioHandler::existeUsuario(std::string nickname){
    return (mapClientes.find(nickname) != mapClientes.end() ||
        mapPropietarios.find(nickname) != mapPropietarios.end() ||
        mapInmobiliarias.find(nickname) != mapInmobiliarias.end());
}

Inmobiliaria* UsuarioHandler::findInmobiliaria(std::string nickname) {
    std::map<std::string, Usuario*>::iterator it = mapInmobiliarias.find(nickname);
    if (it != mapInmobiliarias.end()) {
        return dynamic_cast<Inmobiliaria*>(it->second);
    }
    return NULL;
} 