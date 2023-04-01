#include <string.h>
#ifndef Datatypes_H
#define Datatypes_H



typedef struct DTFecha {
	int dia;
	int mes;
	int anio;
};
typedef struct DTHabitacion{
	int numero;
	float precio;
	int capacidad;
};
typedef struct DTHuesped {
	string nombre;
	string email;
	bool EsFinger;
};

typedef enum EstadoReserva{
	Abierta,Cerrada,Cancelada
};

typedef struct DTReserva{
	int codigo;
	DTFecha checkIn;
	DTFecha checkOut;
	EstadoReserva estado;
	float costo;
	int habitacion;
};
typedef struct DTReservaIndividual : DTReserva {
	bool pagado;
};
typedef struct DTCadena_de_huespedes { //Es para que se pueda implementar un pseudoatributo que permite
	DTHusped huesped; 	     //asociar varios valores de datos de "DTHuesped" a DTReservaGrupal
	cadena_de_huespedes *siguiente_huesped;
};
typedef struct DTReservaGrupal : DTReserva {
	DTCadena_de_huespedes huespedes;
};


#endif
