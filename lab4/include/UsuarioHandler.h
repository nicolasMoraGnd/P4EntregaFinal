#ifndef USUARIOHANDLER_H
#define USUARIOHANDLER_H

#include "Usuario.h"
#include "Cliente.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include <map>
#include <set>
#include <string>

class DTUsuario;

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

        Inmobiliaria* findInmobiliaria(const std::string& nickname) const;
        Usuario* findUsuario(const std::string& nickname) const;
        bool existeUsuario(std::string nickname);

        std::map<std::string, Inmobiliaria*> getInmobiliarias();
        std::set<DTUsuario*> listarPropietarios() const;
};

#endif