#ifndef FACTORY_H
#define FACTORY_H

class IControladorFechaActual;
class ISistemaController;
class IUsuarioController;

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstancia();
        IControladorFechaActual* getControladorFechaActual();
        //TODO: Get interfaces de controladores
        IUsuarioController* getIUsuarioController();
        ISistemaController* getISistemaController();

        ~Factory();
};

#endif