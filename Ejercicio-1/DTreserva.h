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

    virtual ~DTReserva();
    int getCodigo() const ;
    DTFecha getCheckIn() const;
    DTFecha getCheckOut() const ;
    EstadoReserva getEstado() const ;
    float getCosto() const ;
    int getHabitacion() const ;
    void setEstado(EstadoReserva estado) ;
    void setCosto(float costo);
    void setHabitacion(int numHabitacion) ;
    void setCheckIn(DTFecha checkIn) ;
    void setCheckOut(DTFecha checkOut);
};

#endif
