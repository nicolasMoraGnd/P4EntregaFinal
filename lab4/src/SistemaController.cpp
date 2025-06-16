#include "../include/SistemaController.h"

// Inclusiones de los Handlers y Clases del Dominio
#include "../include/UsuarioHandler.h"
#include "../include/InmuebleHandler.h"
#include "../include/PublicacionHandler.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Publicacion.h"
#include "../include/DTNotificacion.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/TipoInmueble.h"

SistemaController* SistemaController::instancia = 0;

SistemaController::SistemaController() {}
SistemaController::~SistemaController() {}

SistemaController* SistemaController::getInstance() {
    if (instancia == 0)
        instancia = new SistemaController();
    return instancia;
}

void SistemaController::eliminarInmueble(int codigoInmueble) {

}

std::set<DTInmuebleListado*> SistemaController::listarInmuebles() {

}

DTInmueble* SistemaController::detalleInmueble(int codigoInmueble) {

}

bool SistemaController::altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio) {

}

std::set<DTPublicacion*> SistemaController::listarPublicacion(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInm) {
    // TODO: toda la logica para filtrar publicaciones
    return std::set<DTPublicacion*>();
}

DTInmueble* SistemaController::detalleInmueblePublicacion(int codigoPublicacion) {
    // TODO: buscar la publicacion en el handler y devolver DTImueble
    return 0;
}