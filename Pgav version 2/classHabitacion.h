#ifndef CLASSHABITACION_H
#define CLASSHABITACION_H

class Habitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    Habitacion(int numero, float precio, int capacidad) {
        this->numero = numero;
        this->precio = precio;
        this->capacidad = capacidad;
    }

    int getNumero() const {
        return numero;
    }

    void setNumero(int numero) {
        this->numero = numero;
    }

    float getPrecio() const {
        return precio;
    }

    void setPrecio(float precio) {
        this->precio = precio;
    }

    int getCapacidad() const {
        return capacidad;
    }

    void setCapacidad(int capacidad) {
        this->capacidad = capacidad;
    }
};
#endif