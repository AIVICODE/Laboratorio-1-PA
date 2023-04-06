#include "DTFecha.h"
#include "EstadoReserva.h"
int getcodigo();
DTFecha getcheckIn();
DTFecha getchechOut();
EstadoReserva getestado();

int setcodigo(int nuevo_codigo); //retorna 0: todo bien; retorna algo diferente a 0: error
int setcheckIn(DTFecha nuevo_checkin);
int setchechOut(DTFecha nuevo_checkout);
int setestado(EstadoReserva nuevo_estado);

void calcularCosto(float precioHabitacion) {
        // Calcula el costo de la reserva en función de la cantidad de días que dura la estadía
        int dias = getCheckOut().diferenciaEnDias(getCheckIn());
        setCosto(dias * precioHabitacion);
    }
