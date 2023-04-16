#ifndef RESERVAINDIVIDUAL_H
#define RESERVAINDIVIDUAL_H

#include "classReserva.h"
#include "DTHuesped.h"
#include "DTFecha.h"

class ReservaIndividual : public Reserva {
private:
    bool pagado;
    DTHuesped* huesped;

public:
    ReservaIndividual(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado,Habitacion* habitacion, Huesped* huesped, bool pagado)
    : Reserva(checkIn, checkOut, estado,habitacion,huesped), pagado(pagado) {}
    

    bool getPagado() const ;
    void setPagado(bool pagado) ;

    float calcularCosto() override ;
};

#endif // RESERVAINDIVIDUAL_H
