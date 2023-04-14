#ifndef DATATYPEDTRESERVA_H
#define DATATYPEDTRESERVA_H

#include "DTFecha.h"
#include "EstadoReserva.h"

class DTReserva {
protected:
    static int ultimoCodigo;
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    int habitacion;
    float costo;
public:
    DTReserva(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion, float costo)
    : checkIn(checkIn), checkOut(checkOut), estado(estado), habitacion(habitacion), costo(costo) {}

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
