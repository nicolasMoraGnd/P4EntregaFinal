#ifndef IUSUARIOCONTROLLER_H
#define IUSUARIOCONTROLLER_H

#include <set>
#include <string>

struct DTUsuario;
struct DTInmuebleAdministrado;

class IUsuarioController{
    public:
        virtual ~IUsuarioController(){}

        // caso de uso altaUsuario
        virtual bool altaCliente(const std:: string& nickname, const std::string contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento) = 0;
        virtual bool altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono) = 0;
        virtual bool altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono) = 0;

        virtual void altaCasa(const std::string& direccion, int numPuerta, int sup, int anio, bool esPH, TipoTecho techo) = 0;
        virtual void altaApartamento(const std::string& direccion, int numPuerta, int sup, int anio, int piso, bool ascensor, float gastos) = 0;
        
        virtual std::set<DTUsuario*> listarPropietarios() = 0;
        virtual void seleccionarPropietario(const std::string& nickname) = 0;

        // caso de uso altaPublicacion
        virtual std::set<DTUsuario*> listarInmobiliarias() = 0;
        virtual std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(const std::string& nicknameInmobiliaria) = 0;

        virtual std::set<DTUsuario*> listarinmobiliariasNoSuscripto(const std::string& nicknameUsuario) = 0;
        virtual void suscribirseAInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria) = 0;
        virtual void desuscribirseDeInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria) = 0;
        virtual std::list<DTNotificacion> consultarNotificaciones(const std::string& nicknameUsuario) = 0;

#endif