#ifndef CLASSRESERVA_H
#define CLASSRESERVA_H

#include "datatypeDTFecha.h"
#include "datatypeDTreserva.h"
#include "classHabitacion.h"
#include "classHuesped.h"

class Reserva {
protected:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    float costo;

    Habitacion* habitacion_;
    Huesped* huesped_;

public:
    Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, Habitacion* habitacion)
        : codigo(codigo), checkIn(checkIn), checkOut(checkOut), estado(estado), habitacion_(habitacion) {
        calcularCosto();
    }

    virtual ~Reserva() {}

    int getCodigo() const {
        return codigo;
    }

    void setCodigo(int codigo) {
        this->codigo = codigo;
    }

    DTFecha getCheckIn() const {
        return checkIn;
    }

    void setCheckIn(DTFecha checkIn) {
        this->checkIn = checkIn;
        calcularCosto();
    }

    DTFecha getCheckOut() const {
        return checkOut;
    }

    void setCheckOut(DTFecha checkOut) {
        this->checkOut = checkOut;
        calcularCosto();
    }

    EstadoReserva getEstado() const {
        return estado;
    }

    void setEstado(EstadoReserva estado) {
        this->estado = estado;
    }

    float getCosto() const {
        return costo;
    }

    void setCosto(float costo) {
        this->costo = costo;
    }

    virtual float calcularCosto() {
        int cantDias = checkOut - checkIn; // suponiendo que se sobrecargó el operador "-" para fechas
        costo = cantDias * habitacion_->getPrecio(); // obteniendo el precio de la habitación a través del getter
        return costo;
    }
};

#endif
