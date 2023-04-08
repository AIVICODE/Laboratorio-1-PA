    
    #include "classHabitacion.h"
    
    Habitacion :: Habitacion(int numero, float precio, int capacidad){
        this->numero = numero;
        this->precio = precio;
        this->capacidad = capacidad;
    }
    int Habitacion :: getNumero() const {
            return numero;
        }

    void Habitacion :: setNumero(int numero) {
        this->numero = numero;
    }

    float Habitacion :: getPrecio() const {
        return precio;
    }

    void Habitacion :: setPrecio(float precio) {
        this->precio = precio;
    }

    int Habitacion  :: getCapacidad() const {
        return capacidad;
    }

    void Habitacion :: setCapacidad(int capacidad) {
        this->capacidad = capacidad;
    }