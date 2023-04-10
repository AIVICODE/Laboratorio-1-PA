#ifndef DATATYPEDTFECHA_H
#define DATATYPEDTFECHA_H
#include <iostream>
#include <cmath>

class DTFecha {
public:
    DTFecha(int dia, int mes, int anio); // Constructor
    void setFecha(int dia, int mes, int anio);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    void imprimir() const;
    int operator-(const DTFecha& fecha) const;

private:
    int dia_;
    int mes_;
    int anio_;
};

DTFecha::DTFecha(int dia, int mes, int anio) {
    setFecha(dia, mes, anio);
}

void DTFecha::setFecha(int dia, int mes, int anio) {
    dia_ = dia;
    mes_ = mes;
    anio_ = anio;
}

int DTFecha::getDia() const {
    return dia_;
}

int DTFecha::getMes() const {
    return mes_;
}

int DTFecha::getAnio() const {
    return anio_;
}

void DTFecha::imprimir() const {
    std::cout << dia_ << "/" << mes_ << "/" << anio_ << std::endl;
}

bool operator==(const DTFecha& fecha1, const DTFecha& fecha2) {
    return (fecha1.getDia() == fecha2.getDia()) &&
           (fecha1.getMes() == fecha2.getMes()) &&
           (fecha1.getAnio() == fecha2.getAnio());
}



#endif