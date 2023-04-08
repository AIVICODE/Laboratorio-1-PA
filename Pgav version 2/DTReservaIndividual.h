#ifndef DATATYPEDTRESERVAINDIVIDUAL_H
#define DATATYPEDTRESERVAINDIVIDUAL_H

#include "DTFecha.h"
#include "EstadoReserva.h"
#include "DTreserva.h"

class DTReservaIndividual : public DTReserva {
private:
    bool pagado;
public:
<<<<<<< HEAD
<<<<<<< HEAD
DTReservaIndividual(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion, bool pagado)
    : DTReserva(checkIn, checkOut, estado, habitacion), pagado(pagado) {}
    
=======
DTReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion, bool pagado)
    : DTReserva(codigo, checkIn, checkOut, estado, habitacion), pagado(pagado) {}
>>>>>>> c071f8b (Algunos cambios a los nombres)
=======
DTReservaIndividual(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion, bool pagado)
    : DTReserva(checkIn, checkOut, estado, habitacion), pagado(pagado) {}
    
>>>>>>> 23fa48b (funcion registro:Reserva Grupal)

    bool getPagado() const { return pagado; }
    void setPagado(bool pagado) { this->pagado = pagado; }
};
#endif