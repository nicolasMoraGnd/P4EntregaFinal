#ifndef CARGADATOS_H
#define CARGADATOS_H

class CargaDatos {
    private:
        static CargaDatos* instance;
        CargaDatos();

    public:
        static CargaDatos* getInstancia();
        static void releaseInstancia();
        ~CargaDatos();
};

#endif