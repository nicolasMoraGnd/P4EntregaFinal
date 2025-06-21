#include "../include/CargaDatos.h"
#include "../include/Factory.h"
#include "../include/IUsuarioController.h"
#include "../include/ISistemaController.h"
#include "../include/IControladorFechaActual.h"
#include "../include/TipoTecho.h"
#include "../include/TipoPublicacion.h"
#include "../include/DTFecha.h"
#include <cstddef>
#include <string>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos* CargaDatos::getInstancia() {
    if (instance == 0)
        instance = new CargaDatos();
    return instance;
}

CargaDatos::CargaDatos() {
    Factory* factory = Factory::getInstancia();
    IUsuarioController* iuc = factory->getIUsuarioController();
    ISistemaController* isc = factory->getISistemaController();
    IControladorFechaActual* icf = factory->getControladorFechaActual();
    //TODO: Cargar los datos de prueba
    
    //carga Clientes
    iuc->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Pérez", "46859342");
    iuc->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");
    iuc->finalizarAltaUsuario();

// Propietario 1 y sus inmuebles (cod: 1, 2)
    iuc->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "123456789012", "99876543");
    iuc->altaCasa("Av. Rivera", 1011, 120, 1995, true, Plano);
    iuc->altaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);
    iuc->finalizarAltaUsuario();

    // Propietario 2 y su inmueble (cod: 3)
    iuc->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "987654321001", "91234567");
    iuc->altaCasa("Camino Maldonado", 1540, 95, 1988, false, Plano);
    iuc->finalizarAltaUsuario();

    // Propietario 3 y su inmueble (cod: 4)
    iuc->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "654321987654", "92345678");
    iuc->altaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);
    iuc->finalizarAltaUsuario();

    // Propietario 4 y su inmueble (cod: 5)
    iuc->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "321098765432", "98765432");
    iuc->altaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);
    iuc->finalizarAltaUsuario();

    // Propietario 5 y sus inmuebles (cod: 6, 7, 8)
    iuc->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "890123456789", "97654321");
    iuc->altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
    iuc->altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
    iuc->altaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);
    iuc->finalizarAltaUsuario();

    // --- Carga de Inmobiliarias y representación de propietarios ---
    iuc->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
    iuc->representarPropietario("marcelom");
    iuc->representarPropietario("jorge88");
    iuc->finalizarAltaUsuario();

    iuc->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy", "Av. Italia 4567", "https://idealhome.uy", "99123456");
    iuc->representarPropietario("marcelom");
    iuc->representarPropietario("martagal");
    iuc->representarPropietario("jorge88");
    iuc->finalizarAltaUsuario();

    iuc->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
    iuc->representarPropietario("robertarce");
    iuc->representarPropietario("soledadf");
    iuc->representarPropietario("jorge88");
    iuc->finalizarAltaUsuario();

    // --- Alta de Administración de Propiedad (necesario para poder publicar) ---
    icf->setNewFechaActual(DTFecha(1, 1, 2010)); // Fecha genérica para la administración
    iuc->altaAdministraPropiedad("casasur123", 1);
    iuc->altaAdministraPropiedad("casasur123", 2);
    iuc->altaAdministraPropiedad("casasur123", 6);
    iuc->altaAdministraPropiedad("idealhome", 5);
    iuc->altaAdministraPropiedad("vivaurbana", 3);
    iuc->altaAdministraPropiedad("vivaurbana", 4);

    // --- Carga de Publicaciones ---
    icf->setNewFechaActual(DTFecha(9, 10, 2011));
    isc->altaPublicacion("idealhome", 5, Alquiler,"Casa ideal para familia en Juan Paullier barrio tranquilo y seguro, con patio y rejas.", 38500.0f);
    icf->setNewFechaActual(DTFecha(15, 1, 2016));
    isc->altaPublicacion("casasur123", 2, Alquiler,"Oportunidad en Av. Brasil: apartamento de 75 m2 bien ubicado cerca de todo.", 28000.0f);
    icf->setNewFechaActual(DTFecha(5, 3, 2019));
    isc->altaPublicacion("casasur123", 2, Alquiler,"Apartamento luminoso en Av. Brasil, piso alto con balcón y vista al este.", 29500.0f);
    icf->setNewFechaActual(DTFecha(3, 4, 2019));
    isc->altaPublicacion("idealhome", 5, Alquiler,"Casa ideal para familia en Juan Paullier barrio tranquilo y seguro, con patio y rejas.", 38500.0f);
    icf->setNewFechaActual(DTFecha(12, 12, 2019));
    isc->altaPublicacion("casasur123", 6, Venta,"Apartamento en Bulevar Artigas, piso 3 muy luminoso con vista despejada y extras.", 375000.0f);
    icf->setNewFechaActual(DTFecha(12, 6, 2020));
    isc->altaPublicacion("casasur123", 1, Venta,"Casa amplia en Av. Rivera, excelente estado, con jardín y garaje doble.", 47000.0f);
    icf->setNewFechaActual(DTFecha(20, 7, 2020));
    isc->altaPublicacion("vivaurbana", 3, Venta,"Casa en Camino Maldonado, próxima a todos los servicios, con fondo y rejas.", 72000.0f);
    icf->setNewFechaActual(DTFecha(4, 3, 2022));
    isc->altaPublicacion("vivaurbana", 4, Alquiler,"Apartamento en Colonia con buena ventilación y cercanía al centro.", 28000.0f);
    icf->setNewFechaActual(DTFecha(12, 9, 2022));
    isc->altaPublicacion("vivaurbana", 4, Venta,"Apartamento en Colonia, piso 12 con vista panorámica. Oportunidad.", 110000.0f);
    icf->setNewFechaActual(DTFecha(1, 10, 2023));
    isc->altaPublicacion("idealhome", 5, Alquiler,"Casa ideal para familia en Juan Paullier barrio tranquilo y seguro, con patio y rejas.", 38500.0f);
    icf->setNewFechaActual(DTFecha(18, 10, 2023));
    isc->altaPublicacion("idealhome", 5, Venta,"Casa en Juan Paullier con 110 m2 fondo y lugar para barbacoa.", 75000.0f);
    icf->setNewFechaActual(DTFecha(19, 10, 2023));
    isc->altaPublicacion("vivaurbana", 3, Alquiler,"Casa en Camino Maldonado con entrada lateral independiente y patio.", 25000.0f);
    icf->setNewFechaActual(DTFecha(20, 11, 2023));
    isc->altaPublicacion("casasur123", 2, Venta,"Apartamento reciclado en Av. Brasil, piso medio, buena iluminación.", 115000.0f);
    
    icf->setNewFechaActual(DTFecha(15, 1, 2024));
    isc->altaPublicacion("vivaurbana", 3, Venta,"Casa con gran terreno en Camino Maldonado, ideal para familia numerosa.", 95000.0f);
    icf->setNewFechaActual(DTFecha(21, 6, 2025)); // Usando fecha actual
    isc->altaPublicacion("idealhome", 5, Alquiler,"Casa en Juan Paullier con patio techado y posibilidad de ampliación.", 39000.0f);
    icf->setNewFechaActual(DTFecha(21, 6, 2025));
    isc->altaPublicacion("vivaurbana", 3, Alquiler,"Casa en Camino Maldonado con posibilidad de cochera y parrillero.", 26000.0f);
    icf->setNewFechaActual(DTFecha(21, 6, 2025));
    isc->altaPublicacion("vivaurbana", 4, Venta,"Apartamento en Colonia reciclado a nuevo, edificio con ascensor.", 130000.0f);

    // --- Carga de Suscripciones ---
    iuc->suscribirseAInmobiliaria("luisito23", "casasur123");
    iuc->suscribirseAInmobiliaria("luisito23", "idealhome");
    iuc->suscribirseAInmobiliaria("anarojo88", "casasur123");
    iuc->suscribirseAInmobiliaria("anarojo88", "idealhome");
    iuc->suscribirseAInmobiliaria("anarojo88", "vivaurbana");
    iuc->suscribirseAInmobiliaria("marcelom", "idealhome");
    iuc->suscribirseAInmobiliaria("robertarce", "idealhome");
    iuc->suscribirseAInmobiliaria("soledadf", "vivaurbana");
    iuc->suscribirseAInmobiliaria("martagal", "vivaurbana");
    iuc->suscribirseAInmobiliaria("jorge88", "casasur123");
    iuc->suscribirseAInmobiliaria("jorge88", "idealhome");
    iuc->suscribirseAInmobiliaria("jorge88", "vivaurbana");
}
