#ifndef FACTORY_H
#define FACTORY_H
#include "IUsuarioController.h"
#include "ISistemaController.h"

class IControladorFechaActual;

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        //TODO: Get interfaces de controladores
        IUsuarioController* getIUsuarioController();
        ISistemaController* getISistemaController();

        ~Factory();
};

#endif