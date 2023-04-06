#include "DTReserva.h"
#include "DTFecha.h"
#include "DTReservaIndividual.h"
#include "DTReservaGrupal.h"
#include "classReserva.h"
#include "classReservaIndividual.h"
#include "classReservaGrupal.h"
#include <string.h>
#include "classHuesped.h"
using namespace std;
vector<Huesped*> los_huespedes;

void registrarReserva(string email, DTReserva * reserva){
	for (Huesped* el_huesped : los_huespedes){
		if (email.compare(el_huesped->GetEmail()) == 0){

		break;
		}
	}
}
