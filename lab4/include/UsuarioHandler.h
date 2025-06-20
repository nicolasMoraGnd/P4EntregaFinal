#ifndef USUARIOHANDLER_H
#define USUARIOHANDLER_H
#include <string>
#include "Usuario.h"
#include "Cliente.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include <map>

class UsuarioHandler {
    private:
        std::map<std::string, Cliente*> mapClientes;
        std::map<std::string, Propietario*> mapPropietarios;
        std::map<std::string, Inmobiliaria*> mapInmobiliarias;
        static UsuarioHandler* instancia;
        UsuarioHandler();

    public:
        static UsuarioHandler* getInstancia();
        ~UsuarioHandler();

        void agregarCliente(Cliente* cliente);
        void agregarPropietario(Propietario* propietario);
        void agregarInmobiliaria(Inmobiliaria* inmobiliaria);

        Inmobiliaria* findInmobiliaria(std::string nickname);
        bool existeUsuario(std::string nickname);

        std::map<std::string, Inmobiliaria*> getInmobiliarias();
};

#endif