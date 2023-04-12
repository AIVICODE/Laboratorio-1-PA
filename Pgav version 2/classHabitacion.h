#ifndef CLASSHABITACION_H
#define CLASSHABITACION_H

class Habitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    // Constructor
    Habitacion(int numero, float precio, int capacidad) {
        // Constructor de Habitacion
        // Asignar los valores de los parámetros a los miembros de datos correspondientes
        this->numero = numero;
        this->precio = precio;
        this->capacidad = capacidad;
    }

    // Getters
    int getNumero() const {
        return numero;
    }

    float getPrecio() const {
        return precio;
    }

    int getCapacidad() const {
        return capacidad;
    }

    // Setters
    void setNumero(int numero) {
        this->numero = numero;
    }

    void setPrecio(float precio) {
        this->precio = precio;
    }

    void setCapacidad(int capacidad) {
        this->capacidad = capacidad;
    }
};

#endif
