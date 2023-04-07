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
	bool existe_reserva=false;
	bool individual_o_grupal = false; //false = individual ; true = grupal
	bool se_encontro_la_habitacion = false;
	Reserva * la_reserva;
	Habitacion * la_habitacion;
	Huedped * el_huesped;
	for (el_huesped : los_huespedes){
		if (email.compare(el_huesped->GetEmail()) == 0){
			se_encontro_huesped=true;
			break;
		}
	}
	if (!se_encontro_huesped){
	//Insertar error aqui
	return;
	}
	for (la_reserva : las_reservas){				
		if(la_reserva->getcodigo() == reserva->getcodigo()){
			existe_reserva=true;
			break;
		}
	}

	for (la_habitacion : las_habitaciones){ //Revisa si la avitación existe
		if (la_habitacion->getnumero() == reserva->gethabitacion()->getnumero()){
			se_encontro_la_habitacion = true;
			break;
		}
	}
	if (!se_encontro_la_habitacion){
		//Insertar error aqui
	}
	try { reserva->Getpagado();}
	catch(){//Se debe incluir si existe la reserva y hay que incluir el nuevo huesped ó hay que crear un nuevo huesped
		individual_o_grupal=true;
		
		if (existe_reserva){
			la_reserva->agregarhuesped(el_huesped);
		}
		//Se crean los punteros. Cambiar los atributos en comunes antes del try 
		//asi se el codigo queda mas compacto
		//La habitacion
		//los huespedes
		vector<Huesped*> los_huespedes_a_reservar;
		las_reservas->push_back(
			       	new ReservaGrupal(
					codigo_de_nueva_reservacion,
					checkIn_de_nueva_reservacion, 
					checkOut_de_nueva_reservavcion, 
					estado_de_nueva_reservacion, 
					la_habitacion,
					los_huespedes_a_reservar
					)
				);
		
		}// fin del catch
		if (!existe_reserva){
		
			string * nombre_del_huesped_a_reservar;
			string * email_del_huesped_a_reservar;
			bool * esfinger_del_huesped_a_reservar;
			//Los atributos en comun
			int *codigo_de_nueva_reservacion;
			DTFecha * checkIn_de_nueva_reservacion;
			DTFecha *checkOut_de_nueva_reservacion;
			EstadoReserva * estado_de_nueva_reservacion;
	
			codigo_de_nueva_reservacion = new int;
			checkIn_de_nueva_reservacion = new DTFecha;
			checkOut_de_nueva_reservacion = new DTFecha;
			estado_de_nueva_reservacion = new EstadoReserva;
			*codigo_de_nueva_reservacion = reserva->getcodigo();
			*checkIn_de_nueva_reservacion = reserva->getcheckIn();
			*checkout_de_nueva_reservacion = reserva->getcheckOut();
			*estado_de_nueva_reservacion = reserva->getestado();
		}
	
} //fin funcion
