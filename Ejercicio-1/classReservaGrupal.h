#ifndef CLASSRESERVAGRUPAL_H
#define CLASSRESERVAGRUPAL_H

#include <vector>
#include <string.h>
#include "classHuesped.h"
#include "DTFecha.h"
#include "classReserva.h"

class ReservaGrupal : public Reserva {
private:
    std::vector<Huesped*> huespedes;
public:
    ReservaGrupal(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, Habitacion* habitacion, Huesped* huesped, std::vector<Huesped*> huespedes)
        : Reserva(checkIn, checkOut, estado, habitacion, huesped), huespedes(huespedes) {}

    const std::vector<Huesped*>& getHuespedes() const ;
    void setHuespedes(const std::vector<Huesped*>& huespedes) ;
    int getCantHuespedes() const ;
    float calcularCosto() override ;
};

#endif
