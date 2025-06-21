#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "IObserver.h"
#include <string>
#include <set>
#include <map>

//foward declarations
class Propietario;
class AdministraPropiedad;
class Inmueble;
class IObserver; //fuck YEAHHHHHHHHHHHHHHHH
struct DTUsuario;
struct DTFecha;
struct DTInmuebleListado;
<<<<<<< HEAD
struct DTNotificacion; //para uso de los metodos con el observer
// struct DTInmuebleAdministrado; Para listarInmueblesAdministrados
=======
>>>>>>> main

// Inmobiliaria hereda de Usuario y es Observer de otra clase (no Inmueble)
// La asociación entre Inmobiliaria e Inmueble se modela a través de la clase asociativa AdministraPropiedad,
// que se encarga de administrar los inmuebles gestionados por la inmobiliaria.

class Inmobiliaria : public Usuario {
private:
    std::string direccionFisica;
    std::string url;
    std::string telefonoInmobiliaria;
    std::set<Propietario*> propietariosRepresentados;
    std::set<AdministraPropiedad*> propiedadesAdministradas;
<<<<<<< HEAD

    //relacion inmobiliarias inmueble
    int key;
    std::map<int, Inmueble*> inmuebles;

    //sujeto para el patron observer
    std::set<IObserver*> suscriptores; //para manejo de observadores
    
=======
    std::set<IObserver*> suscriptores;    
>>>>>>> main

public:
    //constructor y destructor
    Inmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& dirFisica, const std::string& url, const std::string& telInmo);
    virtual ~Inmobiliaria();

    // Getters
    std::string getDireccionFisica() const;
    std::string getUrl() const;
    std::string getTelefonoInmobiliaria() const;
    DTUsuario* getDTUsuario() const; // Sobrescribe Usuario::getDTUsuario

<<<<<<< HEAD
    //propietarios management
=======
    // Gestion de relaciones
>>>>>>> main
    void agregarPropietarioRepresentado(Propietario* prop); // altaUsuario -> representarPropietario
    void agregarAdministracion(AdministraPropiedad* adminProp);
    void desvincularAdministracion(AdministraPropiedad* adminProp);
    std::set<AdministraPropiedad*> getPropiedadesAdministradas() const;
    std::set<Propietario*> getPropietariosRepresentados() const;  

<<<<<<< HEAD
    //asociaciones con inmuebles
    void asociarInmueble(int codigo, Inmueble* inmueble);
    void desasociarInmueble(int codigo);
    std::map<int, Inmueble*> getInmuebles() const;

    // Métodos de "Alta de Administración de Propiedad"
    std::set<DTInmuebleListado*> getInmueblesNoAdminDePropietario() const;
    void altaAdministracionPropiedad(Inmueble* inmuebleAAdmin, const DTFecha& fechaComienzo);

    //METODOS PARA LA GESTION DE SUSCRIPTORES
    void agregarSuscriptor(IObserver* observer);
    void eliminarSuscriptor(IObserver* observer);
    void notificarSuscriptores(DTNotificacion* notificacion);


    // Métodos de "Alta de Publicación"
    std::set<DTInmuebleListado*> getDTInmueblesAdministrados() const; // Para listarInmueblesAdministrados
    // bool crearPublicacionParaInmueble(int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio, const DTFecha& fechaActual, int& outCodigoPublicacion);
=======
    // Metodos de casos de uso
    std::set<DTInmuebleListado*> getInmueblesNoAdminPropietario() const;
    AdministraPropiedad* getAdministracionDeInmueble(int codigoInmueble) const;
    void altaAdministracionPropiedad(Inmueble* inmuebleAAdministrar, const DTFecha& fechaComienzo);

    // Metodos patron observer
    void suscribir(IObserver* obs);
    void desuscribir(IObserver* obs);
    void notificarSuscriptores(const DTNotificacion& notif);  
>>>>>>> main
};

#endif