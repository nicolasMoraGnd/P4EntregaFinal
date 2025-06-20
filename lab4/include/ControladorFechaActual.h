#ifndef CONTROLADORFECHAACTUAL_H
#define CONTROLADORFECHAACTUAL_H

#include "DTFecha.h"
#include "IControladorFechaActual.h"

class ControladorFechaActual : public IControladorFechaActual {
private:
    static ControladorFechaActual* instance;
    DTFecha* fechaActual;
    ControladorFechaActual();

public:
    static ControladorFechaActual* getInstancia();
    static void releaseInstance(); // Metodo para liberar la instancia singleton
    virtual ~ControladorFechaActual();
    virtual DTFecha getFechaActual();
    virtual void setNewFechaActual(const DTFecha& fecha);
};

#endif