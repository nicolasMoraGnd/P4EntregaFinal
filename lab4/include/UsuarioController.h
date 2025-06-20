#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H

#include "IUsuarioController.h"

class UsuarioController : public IUsuarioController{
    private:
        static UsuarioController* instancia;
        UsuarioController();
    public:
        static UsuarioController* getInstance();
        ~UsuarioController();
// caso de uso altaUsuario
        virtual bool altaCliente(const std:: string& nickname, const std::string contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento);
        virtual bool altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono);
        virtual bool altaInmobiliria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono);
// caso de uso altaPublicacion
        virtual std::set<DTUsuario*> listarInmobiliarias();
        virtual std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(const std::string& nicknameInmobiliaria);
};
#endif