#ifndef INMUEBLE_H
#define INMUEBLE_H

#include <string>
#include <set>
#include <map>

class Propietario;
class AdministraPropiedad;
class Inmobiliaria;
struct DTInmueble;

class Inmueble {
private:
    int codigo;
    std::string direccion;
    int numeroPuerta;
    int superficie;
    int anioConstruccion;
    Propietario* propietarioDuenio; // Vínculo al dueño
    std::set<AdministraPropiedad*> administraciones;

     //relacion inmobiliarias inmueble
    int key;
    std::map<int, Inmobiliaria*> inmobiliarias;

public:
    Inmueble(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* dueno);
    virtual ~Inmueble();

    //Getters
    int getCodigo() const;
    std::string getDireccion() const;
    int getNumeroPuerta() const;
    int getSuperficie() const;
    int getAnioConstruccion() const;
    Propietario* getPropietarioDuenio() const;

    //Setters
    void setCodigo(int codigo);
    void setDireccion(const std::string& direccion);
    void setNumeroPuerta(int numeroPuerta);
    void setSuperficie(int superficie);
    void setAnioConstruccion(int anioConstruccion);

    //metodos relacionados con inmobiliarias
    void asociarInmobiliaria(int id, Inmobiliaria* inm);
    void desasociarInmobiliaria(int id);
    std::map<int, Inmobiliaria*> getInmobiliarias() const;
    bool esAdministradoPor(const Inmobiliaria* inm) const;

    //metodos relacionados con administracion de todo el asunto
    bool esAdministradoPor(const Inmobiliaria* inm) const;
    void asociarAdministracionPropiedad(AdministraPropiedad* adminProp);
    void desasociarAdministracionPropiedad(AdministraPropiedad* adminProp);
    std::set<AdministraPropiedad*> getAdministraciones() const;
    void limpiarReferenciasAdministraciones();

    //fk metodos abstractos
    virtual bool esCasa() const = 0;
    void desvincularInmueble();
    virtual DTInmueble* getDTInmueble() const = 0;
};

#endif
