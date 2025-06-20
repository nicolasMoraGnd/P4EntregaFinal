#include "../include/UsuarioController.h"
#include "../include/UsuarioHandler.h"
#include "../include/AdministraPropiedad.h"

UsuarioController* UsuarioController::instancia = 0;

UsuarioController::UsuarioController(){}

UsuarioController::~UsuarioController(){}

UsuarioController* UsuarioController::getInstance(){
    if (instancia == 0)
        instancia = new UsuarioController();
    return instancia;
}

bool UsuarioController::altaCliente(const std::string& nickname, const std::string contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento){
    UsuarioHandler* manejo = UsuarioHandler::getInstancia();
    //paso 1: existe???
    if(manejo->existeUsuario(nickname)){
        return false;
    }
    //paso 2: si no existe y contrasena mayor 6, creo cliente
    if (contrasena.length() < 6){
        return false;
    }
    Cliente* nuevoCliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    //paso 3: agrego cliente
    manejo->agregarCliente(nuevoCliente);
    
    return true;
}

bool UsuarioController::altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono){
    UsuarioHandler* manejo = UsuarioHandler::getInstancia();
    //paso 1: existe?
    if(manejo->existeUsuario(nickname)){
        return false;
    }
    // paso 2: si no existe y contrasena mayor 6, creo prop
    if (contrasena.length() < 6){
        return false;
    }
    Propietario* nuevoProp = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    // paso 3: agrego prop
    manejo->agregarPropietario(nuevoProp);

    return true;
}

bool UsuarioController::altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono){
    UsuarioHandler* manejo = UsuarioHandler::getInstancia();
    // 1 existe?
    if (manejo->existeUsuario(nickname)){
        return false;
    }
    // 2 si no existe y contrasena mayor a 6, creo inm
    if (contrasena.length() < 6){
        return false;
    }
    Inmobiliaria* nuevaInm = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    // paso 3: agrego inmm
    manejo->agregarInmobiliaria(nuevaInm);

    return true;
}

std::set<DTUsuario*> UsuarioController::listarInmobiliarias(){
    std::set<DTUsuario*> res;
    UsuarioHandler* manejo = UsuarioHandler::getInstancia();
    std::map<std::string, Inmobiliaria*> li = manejo->getInmobiliarias();
    for(std::map<std::string, Inmobiliaria*>::iterator it = li.begin(); it != li.end(); ++it){
        Inmobiliaria* inm = it->second;
        DTUsuario* dt = inm->getDTUsuario();
        res.insert(dt);
    }
    return res;
}

std::set<DTInmuebleAdministrado*> UsuarioController::listarInmueblesAdministrados(const std::string& nicknameInmobiliaria){
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Inmobiliaria* inmo = uh->findInmobiliaria(nicknameInmobiliaria);
    std::set<DTInmuebleAdministrado*> resultado;
    if(inmo != 0){
        std::set<AdministraPropiedad*> adminProps = inmo->getPropiedadesAdministradas();
        for(std::set<AdministraPropiedad*>::iterator it = adminProps.begin(); it != adminProps.end(); ++it)
            resultado.insert((*it)->getDTInmuebleAdministrado());
    }
    return resultado;
}

std::list<DTNotificacion> UsuarioController::consultarNotificaciones(const std::string& nicknameUsuario){
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Usuario* user = uh->findUsuario(nicknameUsuario);
    std::list<DTNotificacion> resultado;
    if(Cliente* cli = dynamic_cast<Cliente*>(user)){
        resultado = cli->getNotificacionesPendientes();
        cli->limpiarNotificaciones();
    }
    else if(Propietario* prop = dynamic_cast<Propietario*>(user)){
        resultado = prop->getNotificacionesPendientes();
        prop->limpiarNotificaciones();
    }
    return resultado;
}

void UsuarioController::suscribirseAInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria){
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Usuario* user = uh->findUsuario(nicknameUsuario);
    Inmobiliaria* inm = uh->findInmobiliaria(nicknameInmobiliaria);
    if (user != 0 && inm != 0){
        if(Cliente* cli = dynamic_cast<Cliente*>(user))
            cli->suscribirseAInmobiliaria(inm);
        else if (Propietario* prop = dynamic_cast<Propietario*>(user))
            prop->suscribirseAInmobiliaria(inm);
    }
}

std::set<DTUsuario*> UsuarioController::listarPropietarios(){
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    return uh->listarPropietarios();
}
