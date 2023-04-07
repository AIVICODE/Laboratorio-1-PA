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
    Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, Habitacion* habitacion); 
     
    virtual ~Reserva() {}

    int getCodigo() const;

    void setCodigo(int codigo);

    DTFecha getCheckIn() const;

    void setCheckIn(DTFecha checkIn) ;

    DTFecha getCheckOut() const ;

    void setCheckOut(DTFecha checkOut) ;

    EstadoReserva getEstado() const ;

    void setEstado(EstadoReserva estado) ;

    float getCosto() const ;

    void setCosto(float costo) ;

    virtual float calcularCosto();
};

#endif
