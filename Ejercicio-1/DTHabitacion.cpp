#include "DTHabitacion.h"

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
