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
    virtual ~ControladorFechaActual();
    virtual DTFecha getFechaActual();
    static void releaseInstancia();
    virtual void setNewFechaActual(const DTFecha& fecha);
};

#endif