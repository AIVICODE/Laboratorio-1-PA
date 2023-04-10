#ifndef DATATYPEDTRESERVAGRUPAL_H
#define DATATYPEDTRESERVAGRUPAL_H
#include <vector>
#include <string.h>
#include "DTHuesped.h"
#include "DTFecha.h"
#include "EstadoReserva.h"
#include "DTreserva.h"
class DTReservaGrupal : public DTReserva {
private:
    std::vector<DTHuesped> huespedes;
public:
    DTReservaGrupal( DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion, std::vector<DTHuesped> huespedes)
        : DTReserva(checkIn, checkOut, estado, habitacion), huespedes(huespedes) {}

    const std::vector<DTHuesped>& getHuespedes() const { return huespedes; }
    void setHuespedes(const std::vector<DTHuesped>& huespedes) { this->huespedes = huespedes; }
     int getCantHuespedes() const { return huespedes.size(); }
};
#endif