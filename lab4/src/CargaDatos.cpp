#include "../include/CargaDatos.h"
#include <cstddef>
#include <string>
#include "../include/Factory.h"
#include "../include/IUsuarioController.h"
#include "../include/TipoTecho.h"

CargaDatos* CargaDatos::instance = NULL;

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0)
        instance = new CargaDatos();
    return instance;
}

CargaDatos::CargaDatos() {
    //TODO: Cargar los datos de prueba
    
    //carga Clientes
    altaCliente("luisito23", "qweasd12", "luisito23@gmail.com", "Luis", "Pérez", "46859342");
    altaCliente("anarojo88", "claveAna1", "anarojo88@hotmail.com", "Ana", "Rojo", "31287465");

    //carga Propietario y sus inmuebles
    altaPropietario("marcelom", "banco123", "marcelo.m@gmail.com", 	"Marcelo", "123456789012", "99876543");
    altaCasa("Av. Rivera", 1011, 120, 1995, true, TipoTecho Plano);
    altaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);
    altaPropietario("robertarce", "pass456", "roberto.a@yahoo.com", "Roberto", "987654321001", "91234567");
    altaCasa("Camino Maldonado", 1540, 95, 1988, false, TipoTecho Plano);
    altaPropietario("soledadf", "sole789", "soledad.f@gmail.com", "Soledad", "654321987654", "92345678");
    altaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);
    altaPropietario("martagal", "martA01", "marta.galvez@outlook.com","Marta",  "321098765432", "98765432");
    altaCasa("Juan Paullier", 801, 110, 2000, true, TipoTecho Liviano);
    altaPropietario("jorge88", "jorgepass88", "jorge.rivera@uy.com", "Jorge", "890123456789", "97654321");
    altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
    altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
    altaCasa("Cno. Carrasco", 1576, 140, 2007, true, TipoTecho Plano);

    //carga Inmobiliaria
    altaInmobiliaria("casasur123", "casasur99", "contacto@casasur.com", "Casa Sur", "Canelones 2345", "https://casasur.com.uy", "24012345");
    representarPropietario("marcelom");
    representarPropietario("jorge88");
    altaInmobiliaria("idealhome", "home2025", "info@idealhome.uy", "IHome", "Av. Italia 4567", "https://idealhome.uy", "99123456");
    representarPropietario("marcelom");
    representarPropietario("martagal");
    representarPropietario("jorge88");
    altaInmobiliaria("vivaurbana", "viva4567", "contacto@vivaurbana.com", "Viva Urbana", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
    representarPropietario("robertarce");
    representarPropietario("soledadf");
    representarPropietario("jorge88");

    void setNewFechaActual(const DTFecha& fecha);
    DTFecha(int dia, int mes, int anio);
    altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
    //alta administra Propiedad

    

    //Carga Publicacion
    setNewFechaActual(DTFecha(9, 10, 2011));
    altaPublicacion("idealhome", 5, TipoPublicacion Alquiler,"Casa ideal para familia en Juan Paullier barrio tranquilo y seguro, con patio y rejas.", 38500.0f);
    setNewFechaActual(DTFecha(15, 1, 2016));
    altaPublicacion("casasur123", 2, TipoPublicacion Alquiler,"Oportunidad en Av. Brasil: apartamento de 75 m2 bien ubicado cerca de todo.", 28000.0f);
    setNewFechaActual(DTFecha(5, 3, 2019));
    altaPublicacion("casasur123", 2, TipoPublicacion Alquiler,"Apartamento luminoso en Av. Brasil, piso alto con balcón y vista al este.", 29500.0f);
    setNewFechaActual(DTFecha(3, 4, 2019));
    altaPublicacion("idealhome", 5,TipoPublicacion Alquiler,"Casa ideal para familia en Juan Paullier barrio tranquilo y seguro, con patio y rejas.", 38500.0f);
    setNewFechaActual(DTFecha(12, 12, 2019));
    altaPublicacion("casasur123", 6, TipoPublicacion Venta,"Apartamento en Bulevar Artigas, piso 3 muy luminoso con vista despejada y extras.", 375000.0f);
    setNewFechaActual(DTFecha(12, 6, 2020));
    altaPublicacion("casasur123", 1, TipoPublicacion Venta,"Casa amplia en Av. Rivera, excelente estado, con jardín y garaje doble.", 47000.0f);
    setNewFechaActual(DTFecha(20, 7, 2020));
    altaPublicacion("vivaurbana", 3, TipoPublicacion Venta,"Casa en Camino Maldonado, próxima a todos los servicios, con fondo y rejas.", 72000.0f);
    setNewFechaActual(DTFecha(4, 3, 2022));
    altaPublicacion("vivaurbana", 4, TipoPublicacion Alquiler,"Apartamento en Colonia con buena ventilación y cercanía al centro.", 28000.0f);
    setNewFechaActual(DTFecha(12, 9, 2022));
    altaPublicacion("vivaurbana", 4, TipoPublicacion Venta,"Apartamento en Colonia, piso 12 con vista panorámica. Oportunidad.", 110000.0f);
    setNewFechaActual(DTFecha(1, 10, 2023));
    altaPublicacion("idealhome", 5, TipoPublicacion Alquiler,"Casa ideal para familia en Juan Paullier barrio tranquilo y seguro, con patio y rejas.", 38500.0f);
    setNewFechaActual(DTFecha(18, 10, 2023));
    altaPublicacion("idealhome", 5, TipoPublicacion Venta,"Casa en Juan Paullier con 110 m2 fondo y lugar para barbacoa.", 75000.0f);
    setNewFechaActual(DTFecha(19, 10, 2023));
    altaPublicacion("vivaurbana", 3, TipoPublicacion Alquiler,"Casa en Camino Maldonado con entrada lateral independiente y patio.", 25000.0f);
    setNewFechaActual(DTFecha(20, 11, 2023));
    altaPublicacion("casasur123", 2, TipoPublicacion Venta,"Apartamento reciclado en Av. Brasil, piso medio, buena iluminación.", 115000.0f);
    
    altaPublicacion("vivaurbana", 3, TipoPublicacion Venta,"Casa con gran terreno en Camino Maldonado, ideal para familia numerosa.", 95000.0f);
    setNewFechaActual(DTFecha());
    altaPublicacion("idealhome", 5, TipoPublicacion Alquiler,"Casa en Juan Paullier con patio techado y posibilidad de ampliación.", 39000.0f);
    setNewFechaActual(DTFecha());
    altaPublicacion("vivaurbana", 3, TipoPublicacion Alquiler,"Casa en Camino Maldonado con posibilidad de cochera y parrillero.", 26000.0f)
    setNewFechaActual(DTFecha());
    altaPublicacion("vivaurbana", 4, TipoPublicacion Venta,"Apartamento en Colonia reciclado a nuevo, edificio con ascensor.", 130000.0f);


    void suscribirseAInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria);
    //Carga Subscripcion
    suscribirseAInmobiliaria("luisito23", "casasur123");
    suscribirseAInmobiliaria("luisito23", "idealhome");
    suscribirseAInmobiliaria("anarojo88", "casasur123");
    suscribirseAInmobiliaria("anarojo88", "idealhome");
    suscribirseAInmobiliaria("anarojo88", "vivaurbana");
    suscribirseAInmobiliaria("marcelom", "idealhome");
    suscribirseAInmobiliaria("robertarce", "idealhome");
    suscribirseAInmobiliaria("soledadf", "vivaurbana");
    suscribirseAInmobiliaria("martagal", "vivaurbana");
    suscribirseAInmobiliaria("jorge88", "casasur123");
    suscribirseAInmobiliaria("jorge88", "idealhome");
    suscribirseAInmobiliaria("jorge88", "vivaurbana");





}
