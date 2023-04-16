#include "classReservaIndividual.h"

bool ReservaIndividual::getPagado() const {
    return pagado;
}

void ReservaIndividual::setPagado(bool pagado) {
    this->pagado = pagado;
}

float ReservaIndividual::calcularCosto() {
    int cantDias = checkOut - checkIn; // suponiendo que se sobrecargó el operador "-" para fechas
    float costo = cantDias * habitacion_->getPrecio(); // calculando el costo por días de la habitación
    return costo;
}