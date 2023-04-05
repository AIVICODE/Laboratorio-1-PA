#ifndef DATATYPEDTRESERVAGRUPAL_H
#define DATATYPEDTRESERVAGRUPAL_H
#include <vector>
#include <string.h>
#include "datatypeDTHuesped.h"
#include "datatypeDTFecha.h"
#include "datatypeEstadoReserva.h"
#include "datatypeDTreserva.h"
class DTReservaGrupal : public DTReserva {
private:
    std::vector<DTHuesped*> huespedes;
public:
    DTReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion, std::vector<DTHuesped*> huespedes)
        : DTReserva(codigo, checkIn, checkOut, estado, habitacion), huespedes(huespedes) {}

    const std::vector<DTHuesped*>& getHuespedes() const { return huespedes; }
    void setHuespedes(const std::vector<DTHuesped*>& huespedes) { this->huespedes = huespedes; }
};
#endif