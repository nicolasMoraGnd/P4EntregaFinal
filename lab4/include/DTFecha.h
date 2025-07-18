#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>
#include <ostream>

class DTFecha {
    private:
        int dia, mes, anio;
    public:
        DTFecha(int dia, int mes, int anio);
        DTFecha(const DTFecha& fecha);
        bool operator>=(DTFecha* fecha);
        bool operator<(const DTFecha& otra) const;
        bool operator==(DTFecha* fecha);
        std::string toString();
};

std::ostream& operator<<(std::ostream& os, DTFecha* fecha);

#endif
