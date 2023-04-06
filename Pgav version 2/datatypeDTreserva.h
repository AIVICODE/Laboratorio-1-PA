#ifndef DATATYPEDTRESERVA_H
#define DATATYPEDTRESERVA_H

#include "datatypeDTFecha.h"
#include "datatypeEstadoReserva.h"

class DTReserva {
protected:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    float costo;
    int habitacion;
public:
    DTReserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion)
        : codigo(codigo), checkIn(checkIn), checkOut(checkOut), estado(estado), habitacion(habitacion){}

    virtual ~DTReserva() {}
    int getCodigo() const { return codigo; }
    DTFecha getCheckIn() const { return checkIn; }
    DTFecha getCheckOut() const { return checkOut; }
    EstadoReserva getEstado() const { return estado; }
    float getCosto() const { return costo; }
    int getHabitacion() const { return habitacion; }
    void setEstado(EstadoReserva estado) { this->estado = estado; }
    void setCosto(float costo) { this->costo = costo; }
    void setHabitacion(int numHabitacion) {
    this->habitacion = numHabitacion;
}
    void setCheckIn(DTFecha checkIn) { this->checkIn = checkIn; }
    void setCheckOut(DTFecha checkOut) { this->checkOut = checkOut; }
};

#endif