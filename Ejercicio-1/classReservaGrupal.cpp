#include "classReservaGrupal.h"

const std::vector<Huesped*>& ReservaGrupal::getHuespedes() const { return huespedes; }

void ReservaGrupal::setHuespedes(const std::vector<Huesped*>& huespedes) { this->huespedes = huespedes; }

int ReservaGrupal::getCantHuespedes() const { return huespedes.size(); }

float ReservaGrupal::calcularCosto(){
    int cantDias = checkOut - checkIn; // suponiendo que se sobrecargó el operador "-" para fechas
    float costo = cantDias * habitacion_->getPrecio(); // calculando el costo por días de la habitación
    return costo;
}