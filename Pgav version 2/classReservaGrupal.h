#ifndef CLASSRESERVAGRUPAL_H
#define CLASSRESERVAGRUPAL_H
#include <vector>
#include <string.h>
#include "classHuesped.h"
#include "DTFecha.h"
#include "classReserva.h"
class ReservaGrupal : public Reserva {
private:
    std::vector<Huesped> huespedes;
public:
    ReservaGrupal( DTFecha checkIn, DTFecha checkOut, EstadoReserva estado,Habitacion* habitacion, Huesped* huesped, std::vector<Huesped> huespedes)
        : Reserva(checkIn, checkOut, estado,habitacion,huesped), huespedes(huespedes) {}

    const std::vector<Huesped> getHuespedes() const { return huespedes; }
    void setHuespedes(const std::vector<Huesped>& huespedes) { this->huespedes = huespedes; }
     int getCantHuespedes() const { return huespedes.size(); }
         float calcularCosto() override {
        // Implementación de la función calcularCosto() en DTHabitacion
        // Puedes escribir el cálculo del costo específico para DTHabitacion aquí
        // y actualizar el valor de costo en consecuencia
        return costo;
    }
};
#endif