#ifndef FACTORY_H
#define FACTORY_H

class IControladorFechaActual;
class ISistemaController;
class IUsuarioController;

class ControladorNotificaciones; 


class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
<<<<<<< HEAD
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        ControladorNotificaciones* getControladorNotificaciones(); // Ahora el compilador sabe que ControladorNotificaciones es una clase
        
        //TODO: Get interfaces de controladores
=======
        static Factory* getInstancia();
>>>>>>> main
        ~Factory();
        
        //TODO: Get interfaces de controladores
        IUsuarioController* getIUsuarioController();
        ISistemaController* getISistemaController();
        IControladorFechaActual* getIControladorFechaActual();
};

#endif