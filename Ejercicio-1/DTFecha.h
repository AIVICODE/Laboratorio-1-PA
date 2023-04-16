#ifndef DATATYPEDTFECHA_H
#define DATATYPEDTFECHA_H


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
    int operator-(const DTFecha& fecha) const;
    DTFecha() = default;
private:
    int dia_;
    int mes_;
    int anio_;
};
#endif
