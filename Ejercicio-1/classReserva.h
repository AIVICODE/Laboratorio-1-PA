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
     
    virtual ~Reserva() ;

    int getCodigo() const ;

    void setCodigo(int codigo) ;
    DTFecha getCheckIn() const;

    void setCheckIn(DTFecha checkIn) ;

    DTFecha getCheckOut() const ;

    void setCheckOut(DTFecha checkOut);

    EstadoReserva getEstado() const ;

    void setEstado(EstadoReserva estado) ;

    float getCosto() const ;

    void setCosto(float costo);
    int getNumeroHabitacion() const ;

    virtual float calcularCosto() =0;
};

#endif
