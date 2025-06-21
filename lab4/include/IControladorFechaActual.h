#ifndef ICONTROLADORFECHAACTUAL_H
#define ICONTROLADORFECHAACTUAL_H

#include "DTFecha.h"

class IControladorFechaActual {
    public:
        virtual ~IControladorFechaActual() {}
        virtual DTFecha getFechaActual() = 0;
        virtual void setNewFechaActual(const DTFecha& fecha) = 0;
};

#endif