#ifndef INMUEBLE_H
#define INMUEBLE_H

#include <string>
#include <set>

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

public:
    Inmueble(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, Propietario* dueno);
    virtual ~Inmueble();

    int getCodigo() const;
    std::string getDireccion() const;
    int getNumeroPuerta() const;
    int getSuperficie() const;
    int getAnioConstruccion() const;
    Propietario* getPropietarioDuenio() const;

    void setCodigo(int codigo);
    void setDireccion(const std::string& direccion);
    void setNumeroPuerta(int numeroPuerta);
    void setSuperficie(int superficie);
    void setAnioConstruccion(int anioConstruccion);

    void desvincularInmueble();
    bool esAdministradoPor(const Inmobiliaria* inm) const;
    void asociarAdministracionPropiedad(AdministraPropiedad* adminProp);
    void desasociarAdministracionPropiedad(AdministraPropiedad* adminProp);
    std::set<AdministraPropiedad*> getAdministraciones() const;
    void limpiarReferenciasAdministraciones();

    virtual DTInmueble* getDTInmueble() const = 0;

    virtual DTNotificacion crearDTNotificacion(const std::string& nickInmo, const std::string& texto, TipoPublicacion tipo) const = 0;
};

#endif