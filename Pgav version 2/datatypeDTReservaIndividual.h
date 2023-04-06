#ifndef DATATYPEDTRESERVAINDIVIDUAL_H
#define DATATYPEDTRESERVAINDIVIDUAL_H

#include "datatypeDTFecha.h"
#include "datatypeEstadoReserva.h"
#include "datatypeDTreserva.h"

class DTReservaIndividual : public DTReserva {
private:
    bool pagado;
public:
DTReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion, bool pagado)
    : DTReserva(codigo, checkIn, checkOut, estado, habitacion), pagado(pagado) {}

    bool getPagado() const { return pagado; }
    void setPagado(bool pagado) { this->pagado = pagado; }
};
#endif