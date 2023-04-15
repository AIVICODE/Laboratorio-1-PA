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

    const std::vector<Huesped*>& getHuespedes() const { return huespedes; }
    void setHuespedes(const std::vector<Huesped*>& huespedes) { this->huespedes = huespedes; }
    int getCantHuespedes() const { return huespedes.size(); }
    float calcularCosto() override {
        int cantDias = checkOut - checkIn; // suponiendo que se sobrecargó el operador "-" para fechas
        float costo = cantDias * habitacion_->getPrecio(); // calculando el costo por días de la habitación
        return costo;
    }
};

#endif
