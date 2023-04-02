#include "DTFecha.h"
#include "EstadoReserva.h"
typedef struct DTReserva{
	int codigo;
	DTFecha checkIn;
	DTFecha checkOut;
	EstadoReserva estado;
	float costo;
	int habitacion;
};
