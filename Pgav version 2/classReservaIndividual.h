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
    ReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, float costo, int habitacion, bool pagado, DTHuesped* huesped);

    bool getPagado() const;
    void setPagado(bool pagado);
    DTHuesped* getHuesped() const;
    void setHuesped(DTHuesped* huesped);

    float calcularCosto() override {
        // int cantDias = checkOut - checkIn; // suponiendo que se sobrecargó el operador "-" para fechas
        // costo = cantDias * habitacion.getPrecio(); // calculando el costo por días de la habitación
        // return costo;
    }
};

#endif // RESERVAINDIVIDUAL_H
