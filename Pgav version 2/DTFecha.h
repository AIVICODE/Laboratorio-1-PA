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
    bool operator==(const DTFecha& fecha) const; // Sobrecarga del operador ==
    bool operator<=(const DTFecha& fecha) const; // Sobrecarga del operador <=
    bool operator>=(const DTFecha& fecha) const; // Sobrecarga del operador >=
    DTFecha() = default;
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



bool DTFecha::operator==(const DTFecha& fecha) const {
    return (dia_ == fecha.getDia()) &&
           (mes_ == fecha.getMes()) &&
           (anio_ == fecha.getAnio());
}

bool DTFecha::operator<=(const DTFecha& fecha) const {
    if (anio_ < fecha.getAnio()) {
        return true;
    } else if (anio_ == fecha.getAnio()) {
        if (mes_ < fecha.getMes()) {
            return true;
        } else if (mes_ == fecha.getMes()) {
            return dia_ <= fecha.getDia();
        }
    }
    return false;
}

bool DTFecha::operator>=(const DTFecha& fecha) const {
    if (anio_ > fecha.getAnio()) {
        return true;
    } else if (anio_ == fecha.getAnio()) {
        if (mes_ > fecha.getMes()) {
            return true;
        } else if (mes_ == fecha.getMes()) {
            return dia_ >= fecha.getDia();
        }
    }
    return false;
}

#endif