#ifndef FACTORY_H
#define FACTORY_H

class IControladorFechaActual;

class ControladorNotificaciones; 


class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        ControladorNotificaciones* getControladorNotificaciones(); // Ahora el compilador sabe que ControladorNotificaciones es una clase
        
        //TODO: Get interfaces de controladores
        ~Factory();
};

#endif