#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H

#include "IUsuarioController.h"
#include "TipoTecho.h"
#include "DTInmuebleListado.h"
#include <list>

class DTNotificacion;
class Propietario;
class Inmobiliaria;

class UsuarioController : public IUsuarioController{
    private:
        static UsuarioController* instancia;
        UsuarioController();

        Propietario* propietarioRecordado;
        Inmobiliaria* inmobiliariaRecordado;
    public:
        static UsuarioController* getInstancia();
        ~UsuarioController();

        // Caso de uso altaUsuario
        virtual bool altaCliente(const std::string& nickname, const std::string contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento);
        virtual bool altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono);
        virtual bool altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono);

        // Caso Alta de Usuario
        virtual void altaCasa(const std::string& direccion, int numPuerta, int sup, int anio, bool esPH, TipoTecho techo);
        virtual void altaApartamento(const std::string& direccion, int numPuerta, int sup, int anio, int piso, bool ascensor, float gastos);
        virtual void finalizarAltaUsuario();

        virtual std::set<DTUsuario*> listarPropietarios();
        virtual void seleccionarPropietario(const std::string& nickname);

        // Caso alta administra
        virtual std::set<DTUsuario*> listarInmobiliarias();
        virtual std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(const std::string& nicknameInmobiliaria);
        virtual void altaAdministraPropiedad(const std::string& nicknameInmobiliaria, int codigoInmueble);

        virtual std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(const std::string& nicknameInmobiliaria);

        virtual std::set<DTUsuario*> listarinmobiliariasNoSuscripto(const std::string& nicknameUsuario);
        virtual void suscribirseAInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria);
        virtual void desuscribirseDeInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria);
        virtual std::list<DTNotificacion> consultarNotificaciones(const std::string& nicknameUsuario);
        //void RepresentarPropietario(string nicknamePropietario)
};

#endif