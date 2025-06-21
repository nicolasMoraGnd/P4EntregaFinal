#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/IUsuarioController.h"
#include "../include/ISistemaController.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/IControladorFechaActual.h"
#include <string>
#include <set>

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Eliminar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            exit(0);
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario(){
    Factory* factory = Factory::getInstancia();
    IUsuarioController* iuc = factory->getIUsuarioController();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        usuarioOk = iuc->altaCliente(nickname, contrasena, nombre, email, apellido, documento);
    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = iuc->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = iuc->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    }

    if (usuarioOk){
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            while (salir != 0){
                std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
                
                if (salir == 0) return;

                std::string inmuebleDireccion;
                int numeroPuerta;
                int superficie;
                int anoConstruccion;

                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    std::set<DTUsuario*> propietarios = iuc->listarPropietarios();
                    if(propietarios.empty()) {
                        std::cout << "No hay propietarios" << std::endl;
                    } else {
                        for(std::set<DTUsuario*>::iterator it = propietarios.begin(); it != propietarios.end(); ++it) {
                            std::cout << "- Nickname: " << (*it)->getNickname() << " Nombre: " << (*it)->getNombre() << std::endl;
                        }
                        std::cout << "Nickname propietario a representar: ";
                        std::string nicknamePropietario;
                        std::getline(std::cin, nicknamePropietario);
                        iuc->representarPropietario(nicknamePropietario);
                    }
                    for(std::set<DTUsuario*>::iterator it = propietarios.begin(); it != propietarios.end(); ++it) {
                        delete *it;
                    }
                    propietarios.clear();
                } else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        iuc->altaCasa(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        iuc->altaApartamento(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
                    }
                }
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }
        }
        iuc->finalizarAltaUsuario();
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
        iuc->finalizarAltaUsuario();
    }
}


void altaPublicacion(){
    Factory* factory = Factory::getInstancia();
    ISistemaController* isc = factory->getISistemaController();
    IUsuarioController* iuc = factory->getIUsuarioController();

    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario*> inmobiliarias = iuc->listarInmobiliarias();
    if(inmobiliarias.empty()){
        std::cout << "No hay inmobiliarias registradas";
        return;
    }
    for(std::set<DTUsuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
        std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
    for(std::set<DTUsuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
        delete *it;
    inmobiliarias.clear();
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    
    std::set<DTInmuebleAdministrado*> inmueblesAdministrados = iuc->listarInmueblesAdministrados(nicknameInmobiliaria);
    if(inmueblesAdministrados.empty()){
        std::cout << "La inmobiliaria selecionada no adminstra ningun inmueble";
        return;
    }
    for(std::set<DTInmuebleAdministrado*>::iterator it = inmueblesAdministrados.begin(); it != inmueblesAdministrados.end(); ++it)
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", Direccion" << (*it)->getDireccion() << ", Fecha: " << (*it)->getFechaComienzo().toString() << std::endl;
    for(std::set<DTInmuebleAdministrado*>::iterator it = inmueblesAdministrados.begin(); it != inmueblesAdministrados.end(); ++it)
        delete *it;
    inmueblesAdministrados.clear();
    
    int codigoInmueble;
    std::cout << "Inmueble: ";
    std::cin >> codigoInmueble;
    std::cin.ignore();
    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Texto: ";
    std::string texto;
    std::getline(std::cin, texto);
    std::cout << "Precio: ";
    float precio;
    std::cin >> precio;
    std::cin.ignore();
    isc->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
}

void consultaPublicaciones(){
    Factory* factory = Factory::getInstancia();
    ISistemaController* isc = factory->getISistemaController();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();
    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();
    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    std::cin >> inTipoInmueble;
    std::cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if(inTipoInmueble == 1){  
        tipoInmueble = TI_Casa; 
    }else if(inTipoInmueble == 2){
        tipoInmueble = TI_Apartamento;
    }
    std::cout << "Publicaciones encontradas:\n";
    std::set<DTPublicacion*> publicaciones = isc->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
    if(publicaciones.empty()){
        std::cout << "No hay publicaciones registradas";
        return;
    }
    for(std::set<DTPublicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it){
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", fecha: ";
        DTFecha fechaPub = (*it)->getFecha();
        std::cout << fechaPub.toString() << ", texto: " << (*it)->getTexto() << ", precio: " << (*it)->getPrecio() << ", inmobiliaria: " << (*it)->getInmobiliaria() << std::endl;
    }
    for(std::set<DTPublicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it)
        delete *it;
    publicaciones.clear();

    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    std::cin >> verDetalle;
    std::cin.ignore();
    if (verDetalle == 1){
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();
        std::cout << "Detalle del inmueble:\n";
        DTInmueble* dtInm = isc->detalleInmueblePublicacion(codigoPublicacion);
        if(dtInm != NULL) {
            DTCasa* dtCasa = dynamic_cast<DTCasa*>(dtInm);
            if(dtCasa != NULL) {
                std::cout << "Codigo: " << dtCasa->getCodigo() << ", direccion: " << ", nro. puerta: " << dtCasa->getNumeroPuerta() << ", superficie: " << dtCasa->getSuperficie() << " m2, construccion: " << dtCasa->getAnioConstruccion();
                std::cout << ", PH: " << (dtCasa->getEsPH() ? "Si" : "No") << ", Tipo de techo: ";
                if(dtCasa->getTecho() == Liviano){
                    std::cout << "Liviano" << std::endl;
                } else if (dtCasa->getTecho() == A_dos_aguas) {
                    std::cout << "A dos aguas" << std::endl;
                } else if (dtCasa->getTecho() == Plano) {
                    std::cout << "Plano" << std::endl;
                }
            }else{
                DTApartamento* dtApto = dynamic_cast<DTApartamento*>(dtInm);
                if (dtApto != NULL) {
                    std::cout << "Codigo: " << dtApto->getCodigo() << ", direccion: " << dtApto->getDireccion() << ", nro. puerta: " << dtApto->getNumeroPuerta() << ", superficie: " << dtApto->getSuperficie() << " m2, construccion: " << dtApto->getAnioConstruccion();
                    std::cout << ", piso: " << dtApto->getPiso() << ", ascensor: " << (dtApto->getTieneAscensor() ? "Si" : "No") << ", gastos comunes: " << dtApto->getGastosComunes() << std::endl;
                }
            }
            delete dtInm;

        }
        
    }
}

void eliminarInmueble(){
    Factory* factory = Factory::getInstancia();
    ISistemaController* isc = factory->getISistemaController();
    std::cout << "Listado de inmuebles:\n";
    std::set<DTInmuebleListado*> inmuebles = isc->listarInmuebles();
    for(std::set<DTInmuebleListado*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it)
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", direccion: " << (*it)->getDireccion() << ", propietario: " << (*it)->getPropietario() << std::endl;
    for(std::set<DTInmuebleListado*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it)
        delete *it;
    inmuebles.clear();
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    std::cout << "Detalle del inmueble:\n";
    DTInmueble* dtInm = isc->detalleInmueble(codigoInmueble);
    if(dtInm == NULL){
        std::cout << "Inmueble ingresado no es valido";
        return;
    }
    if(DTCasa* dtCasa = dynamic_cast<DTCasa*>(dtInm)){
        std::string techoStr;
        switch (dtCasa->getTecho()) {
            case Liviano: techoStr = "Liviano"; break;
            case A_dos_aguas: techoStr = "A dos aguas"; break;
            case Plano: techoStr = "Plano"; break;
        }
        std::cout << "Codigo: " << dtCasa->getCodigo() << ", Direccion: " << dtCasa->getDireccion() << ", Numero Puerta: " << dtCasa->getNumeroPuerta() << ", Superficie: " << dtCasa->getSuperficie()
                  << "m2, Construccion: " << dtCasa->getAnioConstruccion() << ",  PH: " << (dtCasa->getEsPH() ? "Si" : "No") << ", Tipo de Techo: " << techoStr << std::endl;
    } else if (DTApartamento* dtApto = dynamic_cast<DTApartamento*>(dtInm)){
        std::cout << "Codigo: " << dtApto->getCodigo() << ", Direccion: " << dtApto->getDireccion() << ", Numero Puerta: " << dtApto->getNumeroPuerta() << ", Superficie: " << dtApto->getSuperficie()
                  << "m2, Construccion: " << dtCasa->getAnioConstruccion() << ", Piso: " << dtApto->getPiso() << ", Ascensor: " << (dtApto->getTieneAscensor() ? "Si" : "No") << ", Gastos comunes: "
                  << dtApto->getGastosComunes() << std::endl;
    }
    delete dtInm;
    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No)";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    if (deseaEliminar == 1){
        isc->eliminarInmueble(codigoInmueble);
    }

}

void suscribirseNotificaciones(){
        Factory* factory = Factory::getInstancia();
        IUsuarioController* iuc = factory->getIUsuarioController();

        std::string nicknameUsuario;
        std::cout << "Ingrese su nickname: ";
        std::getline(std::cin, nicknameUsuario);

        std::cout << "Lista de Inmobiliarias a las que NO esta suscripto:\n";
        std::set<DTUsuario*> inmobiliariasNoSuscripto = iuc->listarInmobiliariasNoSuscripto(nicknameUsuario);
        
        if (inmobiliariasNoSuscripto.empty()) {
        std::cout << "No hay inmobiliarias disponibles para suscribirse o ya esta suscripto a todas." << std::endl;
        } else {
            for (std::set<DTUsuario*>::iterator it = inmobiliariasNoSuscripto.begin(); it != inmobiliariasNoSuscripto.end(); ++it){
                std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
            }
            for(std::set<DTUsuario*>::iterator it = inmobiliariasNoSuscripto.begin(); it != inmobiliariasNoSuscripto.end(); ++it)
                delete *it;
            std::cout << "Nickname de la inmobiliaria a la que desea suscribirse: ";
            std::string nicknameInmobiliaria;
            std::getline(std::cin, nicknameInmobiliaria);
            iuc->suscribirseAInmobiliaria(nicknameUsuario, nicknameInmobiliaria);
            std::cout << "Suscripcion realizada correctamente." << std::endl;
        }
}

void consultaNotificaciones(){
    Factory* factory = Factory::getInstancia();
    IUsuarioController* iuc = factory->getIUsuarioController();

    std::string nicknameUsuario;
    std::cout << "Ingrese su nickname para consultar notificiaciones: ";
    std::getline(std::cin, nicknameUsuario);

    std::list<DTNotificacion> notificaciones = iuc->consultarNotificaciones(nicknameUsuario);

    if (notificaciones.empty()) {
        std::cout << "No tiene notificaciones pendientes." << std::endl;
    } else {
        std::cout << "Notificaciones pendientes:\n";
        for(std::list<DTNotificacion>::iterator it = notificaciones.begin(); it != notificaciones.end(); ++it){
            const DTNotificacion& notif = *it;
            std::cout << "- Inmobiliaria: " << notif.getNickInmo()
                << ", Codigo Inmueble: " << notif.getCodigo()
                << ", Tipo Publicacion: " << (notif.getTipo() == Venta ? "Venta" : "Alquiler")
                << ", Texto: " << notif.getTexto() << std::endl;
        }
    }
}

void eliminarSuscripciones(){
    Factory* factory = Factory::getInstancia();
    IUsuarioController* iuc = factory->getIUsuarioController();
    //REVISAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::set<DTUsuario*> inmobiliarias = iuc->listarInmobiliarias();
    std::set<DTUsuario*> subscribedInmobiliarias;

    std::string nicknameUsuario;
    std::cout << "Ingrese su nickname: ";
    std::getline(std::cin, nicknameUsuario);

    std::cout << "Lista de Inmobiliarias a las que esta suscripto:\n";

    //lista de sucripciones
    for (std::set<DTUsuario*>::iterator it = inmobiliarias.begin();
     it != inmobiliarias.end(); ++it) {

    DTUsuario* dtU = *it;

    bool isSubscribed = true;
    std::set<DTUsuario*> notSubscribed = iuc->listarInmobiliariasNoSuscripto(nicknameUsuario);
    for (std::set<DTUsuario*>::iterator itNot = notSubscribed.begin();
         itNot != notSubscribed.end(); ++itNot) {

        DTUsuario* usuarioNoSuscrito = *itNot;

        if (dtU->getNickname() == usuarioNoSuscrito->getNickname()) {
            isSubscribed = false;
        }

        delete usuarioNoSuscrito;
        if (!isSubscribed)
            return;
    }

    if (isSubscribed) {
        subscribedInmobiliarias.insert(dtU);
    } else {
        delete dtU;
    }

    if (subscribedInmobiliarias.empty()) {
        std::cout << "No esta suscripto a ninguna inmobiliaria." << std::endl;
    } else {
        for (std::set<DTUsuario*>::iterator it = subscribedInmobiliarias.begin();
     it != subscribedInmobiliarias.end(); ++it) {

    DTUsuario* dtU = *it;

    std::cout << "- Nickname: " << dtU->getNickname()
              << ", Nombre: " << dtU->getNombre() << std::endl;

    delete dtU;
}

    std::cout << "Nickname de la inmobiliaria de la que desea desuscribirse: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);

    iuc->desuscribirseDeInmobiliaria(nicknameUsuario, nicknameInmobiliaria);

    std::cout << "Desuscripcion realizada correctamente." << std::endl;
    }
}

}

void altaAdministracionPropiedad(){
    Factory* factory = Factory::getInstancia();
    IUsuarioController* iuc = factory->getIUsuarioController();

    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario*> inmobiliarias = iuc->listarInmobiliarias();
    if(inmobiliarias.empty()){
        std::cout << "No hay inmobiliarias";
        return;
    }
    for(std::set<DTUsuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
        std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
    for(std::set<DTUsuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
        delete *it;
    inmobiliarias.clear();
    
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    std::set<DTInmuebleListado*> inmuebles = iuc->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    if(inmuebles.empty()){
        std::cout << "Esta inmobiliaria no tiene inmuebles para administrar";
        return;
    }
    for(std::set<DTInmuebleListado*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it)
        std::cout << "- Codigo :" << (*it)->getCodigo() << ", direccion: " << (*it)->getDireccion() << ", porpietario: " << (*it)->getPropietario() << std::endl;
    for(std::set<DTInmuebleListado*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it)
        delete *it;
    inmuebles.clear();
    std::cout << "Codigo del inmueble a administrar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    iuc->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
}

void cargarDatos(){
    CargaDatos::getInstancia();
}

 void verFechaActual(){
    Factory* factory = Factory::getInstancia();
    IControladorFechaActual* cfecha = factory->getIControladorFechaActual();
    DTFecha fechaActual = cfecha->getFechaActual();
    std::cout << "fecha actual: " << &fechaActual;
 }

 void asignarFechaActual(){
    Factory* factory = Factory::getInstancia();
    IControladorFechaActual* cfecha = factory->getIControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    DTFecha nuevaFecha(dia, mes, ano);
    cfecha->setNewFechaActual(nuevaFecha);
 }