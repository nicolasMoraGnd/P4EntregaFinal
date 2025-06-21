#include "../include/CargaDatos.h"
#include "../include/Factory.h"
#include "../include/IUsuarioController.h"
#include <cstddef>
#include <string>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos* CargaDatos::getInstancia() {
    if (instance == 0)
        instance = new CargaDatos();
    return instance;
}

CargaDatos::CargaDatos() {    
    //carga Clientes
    altaCliente("luisito23", "qweasd12", "luisito23@gmail.com", "Luis", "Pérez", "46859342");
    altaCliente("anarojo88", "claveAna1", "anarojo88@hotmail.com", "Ana", "Rojo", "31287465");

    //carga Propietario
    altaPropietario("marcelom", "banco123", "marcelo.m@gmail.com", 	"Marcelo", "123456789012", "99876543");
    altaPropietario("robertarce", "pass456", "roberto.a@yahoo.com", "Roberto", "987654321001", "91234567");
    altaPropietario("soledadf", "sole789", "soledad.f@gmail.com", "Soledad", "654321987654", "92345678");
    altaPropietario("martagal", "martA01", "marta.galvez@outlook.com","Marta",  "321098765432", "98765432");
    altaPropietario("jorge88", "jorgepass88", "jorge.rivera@uy.com", "Jorge", "890123456789", "97654321");

    //carga Inmobiliaria
    altaInmobiliaria("casasur123", "casasur99", "contacto@casasur.com", "Casa Sur", "Canelones 2345", "https://casasur.com.uy", "24012345");
    altaInmobiliaria("idealhome", "home2025", "info@idealhome.uy", "IHome", "Av. Italia 4567", "https://idealhome.uy", "99123456");
    altaInmobiliaria("vivaurbana", "viva4567", "contacto@vivaurbana.com", "Viva Urbana", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
}