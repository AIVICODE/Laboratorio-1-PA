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

int DTFecha::operator-(const DTFecha& fecha) const {
    // calcular la diferencia en días entre las dos fechas
    int dias1 = anio_*365 + mes_*30 + dia_;
    int dias2 = fecha.anio_*365 + fecha.mes_*30 + fecha.dia_;
    return std::abs(dias1 - dias2);
}

#endif