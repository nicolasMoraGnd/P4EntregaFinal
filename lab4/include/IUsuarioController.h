#ifndef IUSUARIOCONTROLLER_H
#define IUSUARIOCONTROLLER_H

#include <set>
#include <string>

struct DTInmuebleAdministrado;
struct DTUsuario;

class IUsuarioController{
    public:
    private:
        virtual ~IUsuarioController(){}

        virtual bool altaCliente(const std::string& nickname, const std::string& constrasena, const std::string& email, const std::string& nombre, const std::string& apellido, const std::string& documento) = 0;
        virtual bool altaPropietario(const std::string& nickname, const std::string& constrasena, const std::string& email, const std::string& nombre, const std::string& cuentaBancaria, const std::string& telefono) = 0;
        virtual bool altaInmobiliaria(const std::string& nickname, const std::string& constrasena, const std::string& email, const std::string& nombre, const std::string& direccion, const std::string& url, const std::string& telefono) = 0;

        virtual std::set<DTUsuario*> listarInmobiliarias() = 0;

        virtual std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(const std::string& nicknameInmobiliaria) = 0;

}:

#endif