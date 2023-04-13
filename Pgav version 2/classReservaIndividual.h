#ifndef RESERVAINDIVIDUAL_H
#define RESERVAINDIVIDUAL_H

#include "classReserva.h"
#include "DTHuesped.h"
#include "DTFecha.h"

class ReservaIndividual : public Reserva {
private:
    bool pagado;
    DTHuesped* huesped;

public:
    ReservaIndividual(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado,Habitacion* habitacion, Huesped* huesped, bool pagado)
    : Reserva(checkIn, checkOut, estado,habitacion,huesped), pagado(pagado) {}
    

    bool getPagado() const { return pagado; }
    void setPagado(bool pagado) { this->pagado = pagado; }

    float calcularCosto() override {
        int cantDias = checkOut - checkIn; // suponiendo que se sobrecargó el operador "-" para fechas
        float costo = cantDias * habitacion_->getPrecio(); // calculando el costo por días de la habitación
        return costo;
    }
};

#endif // RESERVAINDIVIDUAL_H
