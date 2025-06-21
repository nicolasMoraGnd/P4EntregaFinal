#include "../include/DTFecha.h"
#include <sstream>
#include <iostream>

DTFecha::DTFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

DTFecha::DTFecha(const DTFecha& fecha) : dia(fecha.dia), mes(fecha.mes), anio(fecha.anio) {}

bool DTFecha::operator>=(DTFecha* fecha) {
    return (this->anio > fecha->anio || (this->anio == fecha->anio && this->mes > fecha->mes) || (this->anio == fecha->anio && this->mes == fecha->mes && this->dia >= fecha->dia));
}

bool DTFecha::operator<(const DTFecha& fecha) const {
    if (this->anio != fecha.anio) return this->anio < fecha.anio;
    if (this->mes != fecha.mes) return this->mes < fecha.mes;
    return this->dia < fecha.dia;
}

bool DTFecha::operator==(DTFecha* fecha) {
    if (fecha == NULL) return false;
    return this->anio == fecha->anio && this->mes == fecha->mes && this->dia == fecha->dia;
}

std::string DTFecha::toString(){
    std::stringstream ss;
    ss << this->dia << "/" << this->mes << "/" << this->anio;
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, DTFecha* fecha) {
    os << fecha->toString();
    return os;
}