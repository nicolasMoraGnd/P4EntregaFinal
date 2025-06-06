#ifndef CONTROLADORFECHAACTUAL_H
#define CONTROLADORFECHAACTUAL_H

#include "DTFecha.h"
#include "IControladorFechaActual.h"

class ControladorFechaActual : public IControladorFechaActual  {
    private:
        static ControladorFechaActual* instance;
        DTFecha fechaActual;
        ControladorFechaActual();

    public:
        static ControladorFechaActual* getInstance();
        virtual DTFecha getFechaActual() const;
        virtual void setNewFechaActual(const DTFecha& fecha);
        ~ControladorFechaActual();
};

#endif