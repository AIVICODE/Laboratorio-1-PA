#ifndef DATATYPEDTHABITACION_H
#define DATATYPEDTHABITACION_H

class DTHabitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    DTHabitacion(int numero, float precio, int capacidad);
    int getNumero();
    float getPrecio();
    int getCapacidad();
};

DTHabitacion::DTHabitacion(int numero, float precio, int capacidad) {
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}

int DTHabitacion::getNumero() {
    return this->numero;
}

float DTHabitacion::getPrecio() {
    return this->precio;
}

int DTHabitacion::getCapacidad() {
    return this->capacidad;
}

#endif
