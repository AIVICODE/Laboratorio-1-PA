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
vector<Reserva*> las_reservas;

void registrarReserva(string email, DTReserva * reserva){
	bool se_encontro_huesped = false;
	for (Huesped* el_huesped : los_huespedes){
		if (email.compare(el_huesped->GetEmail()) == 0){
			se_encontro_huesped=true;
			break;
		}
	}
	if (se_encontro_huesped){
		try {
			reserva->Getpagado();
		}
		catch(){
			/*
			bool existe_reserva=false;
			for (Reserva * la_reserva : las_reservas){
				if(la_reserva->getcodigo() == reserva->getcodigo()){
					existe_reserva=true;
				}
			}
			*/
			if 
			vector<Huesped*> los_huespedes_a_reservar;
			string * nombre_del_huesped_a_reservar;
			string * email_del_huesped_a_reservar ;
			bool * esfinger_del_huesped_a_reservar;
			int *codigo_de_nueva_reservacion;
			DTFecha * checkIn_de_nueva_reservacion;
			for(DTHuesped * el_huesped : reserva->gethuestedes()){
						nombre_del_huesped_a_reservar = new string;
						email_del_huesped_a_reservar = new string;
						esfinger_del_huesped_a_reservar = new bool;
						
						*nombre_del_huesped_a_reservar = el_huesped->gernombre();
						*email_del_huesped_a_reservar = el_huesped->getemail();
						*esfinger = el_huesped->getesfinger();
				los_huespedes_a_reservar->push_back(
						new Huesped(nombre_del_huesped_a_reservar,email_del_huesped_a_reservar)
						);
				
			}
			Reserva * reserva_temp = new ReservaGrupal(reserva->getcodigo(),reserva->getcheckIn(),reserva->getchackOut(),reserva->getestado(),);
		
		}
	}
}
