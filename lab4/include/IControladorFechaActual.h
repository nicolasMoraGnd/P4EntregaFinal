#ifndef ICONTROLADORFECHAACTUAL_H
#define ICONTROLADORFECHAACTUAL_H

struct DTFecha;

class IControladorFechaActual {
    public:
        virtual ~IControladorFechaActual() {}
        virtual DTFecha getFechaActual() = 0;
        virtual void setNewFechaActual(const DTFecha& fecha) = 0;
};

#endif