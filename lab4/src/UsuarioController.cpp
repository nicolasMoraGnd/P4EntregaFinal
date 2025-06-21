#include "../include/UsuarioController.h"
#include "../include/UsuarioHandler.h"
#include "../include/AdministraPropiedad.h"
#include "../include/InmuebleHandler.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/InmuebleHandler.h"
#include "../include/ControladorFechaActual.h"

UsuarioController* UsuarioController::instancia = 0;

UsuarioController::UsuarioController(){
    this->propietarioRecordado = NULL;
    this->inmobiliariaRecordado = NULL;
}

UsuarioController::~UsuarioController(){}

UsuarioController* UsuarioController::getInstancia(){
    if (instancia == 0)
        instancia = new UsuarioController();
    return instancia;
}

bool UsuarioController::altaCliente(const std::string& nickname, const std::string contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento){
    UsuarioHandler* manejo = UsuarioHandler::getInstancia();
    //paso 1: existe???
    if(manejo->existeUsuario(nickname))
        return false;
    
    //paso 2: si no existe y contrasena mayor 6, creo cliente
    if (contrasena.length() < 6)
        return false;
    
    Cliente* nuevoCliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    //paso 3: agrego cliente
    manejo->agregarCliente(nuevoCliente);
    
    return true;
}

bool UsuarioController::altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono){
    UsuarioHandler* manejo = UsuarioHandler::getInstancia();
    //paso 1: existe?
    if(manejo->existeUsuario(nickname))
        return false;
    
    // paso 2: si no existe y contrasena mayor 6, creo prop
    if (contrasena.length() < 6)
        return false;
    
    Propietario* nuevoProp = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    // paso 3: agrego prop
    manejo->agregarPropietario(nuevoProp);

    // paso 4: recuerdo propietario
    this->propietarioRecordado = nuevoProp;

    return true;
}

bool UsuarioController::altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono){
    UsuarioHandler* manejo = UsuarioHandler::getInstancia();
    // 1 existe?
    if (manejo->existeUsuario(nickname))
        return false;

    // 2 si no existe y contrasena mayor a 6, creo inm
    if (contrasena.length() < 6)
        return false;

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

void UsuarioController::altaCasa(const std::string& direccion, int numPuerta, int sup, int anio, bool esPH, TipoTecho techo){
    if(this->propietarioRecordado == 0)
        return;
    InmuebleHandler* ih = InmuebleHandler::getInstancia();
    int nuevoCodigo = ih->getSiguienteCodigo();
    Casa* nuevaCasa = new Casa(nuevoCodigo, direccion, numPuerta, sup, anio, this->propietarioRecordado, esPH, techo);
    this->propietarioRecordado->agregarInmueble(nuevaCasa);
    ih->addInmueble(nuevaCasa);
}

void UsuarioController::altaApartamento(const std::string& direccion, int numPuerta, int sup, int anio, int piso, bool ascensor, float gastos){
    if(this->propietarioRecordado == 0)
        return;
    InmuebleHandler* ih = InmuebleHandler::getInstancia();
    int nuevoCodigo = ih->getSiguienteCodigo();
    Apartamento* nuevoApto = new Apartamento(nuevoCodigo, direccion, numPuerta, sup, anio, this->propietarioRecordado, gastos, piso, ascensor);
    this->propietarioRecordado->agregarInmueble(nuevoApto);
    ih->addInmueble(nuevoApto);
}

void UsuarioController::finalizarAltaUsuario(){
    this->propietarioRecordado = NULL;
}

void UsuarioController::altaAdministraPropiedad(const std::string& nicknameInmobiliaria, int codigoInmueble){
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    InmuebleHandler* ih = InmuebleHandler::getInstancia();
    IControladorFechaActual* cf = ControladorFechaActual::getInstancia();

    Inmobiliaria* inmo = uh->findInmobiliaria(nicknameInmobiliaria);
    Inmueble* inm = ih->findInmueble(codigoInmueble);

    if(inmo != 0 && inm != 0 && !inm->esAdministradoPor(inmo)){
        DTFecha fechaActual = cf->getFechaActual();
        inmo->altaAdministracionPropiedad(inm, fechaActual);
    }
}

std::set<DTInmuebleListado*> UsuarioController::listarInmueblesNoAdministradosInmobiliaria(const std::string& nicknameInmobiliaria){
    UsuarioHandler* uh = UsuarioHandler::getInstancia();
    Inmobiliaria* inmo = uh->findInmobiliaria(nicknameInmobiliaria);
    if(inmo != 0)
        return inmo->getInmueblesNoAdminPropietario();
    return std::set<DTInmuebleListado*>();
}