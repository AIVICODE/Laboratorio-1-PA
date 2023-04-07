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
vector<Habitacion*> las_habitaciones;

void registrarReserva(string email, DTReserva * reserva){
	bool se_encontro_huesped = false;
	for (Huesped* el_huesped : los_huespedes){
		if (email.compare(el_huesped->GetEmail()) == 0){
			se_encontro_huesped=true;
			break;
		}
	}
	if (se_encontro_huesped){
	//Insertar error aqui
	return;
	}
	try { reserva->Getpagado();}
	catch(){
		/*
		bool existe_reserva=false;
		for (Reserva * la_reserva : las_reservas){				
		if(la_reserva->getcodigo() == reserva->getcodigo()){
				existe_reserva=true;
			}
		}
		*/
		//if 
		bool se_encontro_la_habitacion =false;
		//Se crean los punteros. Cambiar los atributos en comunes antes del try 
		//asi se el codigo queda mas compacto
		//La habitacion
		Habitacion * la_habitacion;
		//los hespedes
		vector<Huesped*> los_huespedes_a_reservar;
		string * nombre_del_huesped_a_reservar;
		string * email_del_huesped_a_reservar;
		bool * esfinger_del_huesped_a_reservar;
		//Los atributos en comun
		int *codigo_de_nueva_reservacion;
		DTFecha * checkIn_de_nueva_reservacion;
		DTFecha *checkOut_de_nueva_reservacion;
		EstadoReserva * estado_de_nueva_reservacion;
		for (la_habitacion : las_habitaciones){
			if (la_habitacion->getnumero() == reserva->gethabitacion()){
				se_encontro_la_habitacion = true;
				break;
			}
		}
		if (!se_encontro_la_habitacion){
		//Insertar error aqui
		}
		for ()
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
		codigo_de_nueva_reservacion = new int;
		checkIn_de_nueva_reservacion = new DTFecha;
		checkOut_de_nueva_reservacion = new DTFecha;
		estado_de_nueva_reservacion = new EstadoReserva;
		*codigo_de_nueva_reservacion = reserva->getcodigo();
		*checkIn_de_nueva_reservacion = reserva->getcheckIn();
		*checkout_de_nueva_reservacion = reserva->getcheckOut();
		*estado_de_nueva_reservacion = reserva->getestado();
		las_reservas->push_back(
			       	new ReservaGrupal(
					codigo_de_nueva_reservacion,
					checkIn_de_nueva_reservacion, 
					checkOut_de_nueva_reservavcion, 
					estado_de_nueva_reservacion, 
					los_huespedes_a_reservar
					)
				);
		
		}// fin del catch
	
} //fin funcion
