#ifndef DATATYPEDTRESERVAINDIVIDUAL_H
#define DATATYPEDTRESERVAINDIVIDUAL_H

#include "DTFecha.h"
#include "EstadoReserva.h"
#include "DTreserva.h"

class DTReservaIndividual : public DTReserva {
private:
    bool pagado;
public:
DTReservaIndividual(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion,float costo, bool pagado)
    : DTReserva(checkIn, checkOut, estado, habitacion,costo), pagado(pagado) {}
    

    bool getPagado() const;
    void setPagado(bool pagado);
};
#endif