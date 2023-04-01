#include "datatypeDTFecha.h"
#include "datatypeEstadoReserva.h"
class Reserva{
    protected:
        int * codigo;
        DTFecha * checkIn;
        DTFecha * checkOut;
        EstadoReserva * estado;
    public:
        virtual float CalcularCosto();
};

void calcularCosto(float precioHabitacion) {
        // Calcula el costo de la reserva en función de la cantidad de días que dura la estadía
        int dias = getCheckOut().diferenciaEnDias(getCheckIn());
        setCosto(dias * precioHabitacion);
    }