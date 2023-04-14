#ifndef CLASSRESERVA_H
#define CLASSRESERVA_H

#include "DTFecha.h"
#include "classHabitacion.h"
#include "classHuesped.h"
#include "EstadoReserva.h"

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
        // Constructor que acepta punteros a Habitacion y Huesped
    Reserva(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, Habitacion* habitacion, Huesped* huesped)
        : checkIn(checkIn), checkOut(checkOut), estado(estado), habitacion_(habitacion), huesped_(huesped) {
        // Resto del código del constructor
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
    }

    DTFecha getCheckOut() const {
        return checkOut;
    }

    void setCheckOut(DTFecha checkOut) {
        this->checkOut = checkOut;
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
    int getNumeroHabitacion() const {
    return habitacion_->getNumero();
    }

    virtual float calcularCosto() =0;
};

#endif
