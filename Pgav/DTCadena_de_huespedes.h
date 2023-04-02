#include "DTHusped.h"
typedef struct DTCadena_de_huespedes { //Es para que se pueda implementar un pseudoatributo que permite
	DTHusped huesped; 	     //asociar varios valores de datos de "DTHuesped" a DTReservaGrupal
	cadena_de_huespedes *siguiente_huesped;
};
