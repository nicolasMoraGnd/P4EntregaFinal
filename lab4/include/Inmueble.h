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
    Propietario* getPropietarioDuenio() const;

    // Metodo de [1] (pagina 4, paso 3.2.2)
    bool esAdministradoPor(const Inmobiliaria* inm) const;

    // Metodo de [1] (pagina 5, paso 5.3)
    void asociarAdministracionPropiedad(AdministraPropiedad* adminProp);
    void desasociarAdministracionPropiedad(AdministraPropiedad* adminProp); // Para logica de eliminación

    virtual DTInmueble* getDTInmueble() const = 0;
    std::set<AdministraPropiedad*> getAdministraciones() const;
    void limpiarReferenciasAdministraciones(); // Para "Eliminar Inmueble"
};

#endif