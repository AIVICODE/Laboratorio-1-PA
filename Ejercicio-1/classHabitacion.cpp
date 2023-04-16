#include "classHabitacion.h"

// Implementación del constructor
Habitacion::Habitacion(int numero, float precio, int capacidad) {
    // Constructor de Habitacion
    // Asignar los valores de los parámetros a los miembros de datos correspondientes
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}

// Implementaciones de los getters
int Habitacion::getNumero() const {
    return numero;
}

float Habitacion::getPrecio() const {
    return precio;
}

int Habitacion::getCapacidad() const {
    return capacidad;
}

// Implementaciones de los setters
void Habitacion::setNumero(int numero) {
    this->numero = numero;
}

void Habitacion::setPrecio(float precio) {
    this->precio = precio;
}

void Habitacion::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}