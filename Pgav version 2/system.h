#ifndef SYSTEMA_H
#define SYSTEMA_H
#include <list>
#include <string>
#include <vector>
#include "DTHuesped.h"
#include "DTHabitacion.h"
#include "DTreserva.h"
#include "define.h"
#include "classHuesped.h"
#include "DTReservaIndividual.h"
#include "DTREservaGrupal.h"
#include "DTHuesped.cpp"

class Systema {
private:
    std::vector<DTHuesped*> huespedes;
    std::vector<DTHabitacion*> habitaciones;
    std::vector<DTReserva*> reservas;

public:
    Systema() {}

    ~Systema() {
        for (auto huesped : huespedes) {
            delete huesped;
        }
        for (auto habitacion : habitaciones) {
            delete habitacion;
        }
        for (auto reserva : reservas) {
            delete reserva;
        }
    }

    void agregarHuesped(std::string nombre, std::string email, bool esFinger) {
        for (auto huesped : huespedes) {
            if (huesped->getEmail().compare(email) == 0) {
                throw std::invalid_argument("Ya existe un huesped registrado con el mismo email.");
            }
        }
        DTHuesped* nuevoHuesped = new DTHuesped(nombre, email, esFinger);
        huespedes.push_back(nuevoHuesped);
    }

    void agregarHabitacion(int numero, float precio, int capacidad) {
        for (auto habitacion : habitaciones) {
            if (habitacion->getNumero() == numero) {
                throw std::invalid_argument("Ya existe una habitacion registrada con el mismo numero.");
            }
        }
        DTHabitacion* nuevaHabitacion = new DTHabitacion(numero, precio, capacidad);
        habitaciones.push_back(nuevaHabitacion);
    }

    DTHuesped** obtenerHuespedes(int& cantHuespedes) {
        cantHuespedes = huespedes.size();
        DTHuesped** listaHuespedes = new DTHuesped*[cantHuespedes];
        for (int i = 0; i < cantHuespedes; i++) {
            listaHuespedes[i] = new DTHuesped(*huespedes[i]);
        }
        return listaHuespedes;
    }

    DTHabitacion** obtenerHabitaciones(int& cantHabitaciones) {
        cantHabitaciones = habitaciones.size();
        DTHabitacion** listaHabitaciones = new DTHabitacion*[cantHabitaciones];
        for (int i = 0; i < cantHabitaciones; i++) {
            listaHabitaciones[i] = new DTHabitacion(*habitaciones[i]);
        }
        return listaHabitaciones;
    }
        void registrarReserva(std::string email, DTReserva* reserva) {
    // Buscamos el huesped correspondiente al email dado en la lista de huespedes del sistema
    DTHuesped* dtHuesped = nullptr;
    for (auto huesped : huespedes) {
        if (huesped->getEmail().compare(email) == 0) {
            dtHuesped = huesped;
            break;
        }
    }
    if (dtHuesped == nullptr) {
        throw std::invalid_argument("El huesped no esta registrado en el sistema.");
    }

    // Buscamos la habitación correspondiente al número dado en la lista de habitaciones del sistema
    DTHabitacion* dtHabitacion = nullptr;
    for (auto habitacion : habitaciones) {
        if (habitacion->getNumero() == reserva->getHabitacion()) {
            dtHabitacion = habitacion;
            break;
        }
    }
    if (dtHabitacion == nullptr) {
        throw std::invalid_argument("La habitacion no esta registrada en el sistema.");
    }
    /*SOLO PARA PRUEBAS ACA VAN LAS INSTANCIAS REALEAS DE RESERVA*/
    // Verificar el tipo de reserva
    if (DTReservaIndividual* individual = dynamic_cast<DTReservaIndividual*>(reserva)) {
        // Manejar la reserva individual
<<<<<<< HEAD
        DTReservaIndividual* nuevareservaindividual = new DTReservaIndividual(individual->getCheckIn(), individual->getCheckOut(), individual->getEstado(), individual->getHabitacion(),individual ->getPagado());
=======
        DTReserva* dtReserva = new DTReserva(individual->getCheckIn(), individual->getCheckOut(), individual->getEstado(), individual->getHabitacion());
        reservas.push_back(dtReserva);
>>>>>>> 23fa48b (funcion registro:Reserva Grupal)
    } else if (DTReservaGrupal* grupal = dynamic_cast<DTReservaGrupal*>(reserva)) {
         // Manejar la reserva grupal
        if (grupal->getHuespedes().size() <= 1) {
            throw std::invalid_argument("La reserva grupal debe tener al menos dos huespedes.");
        }
<<<<<<< HEAD
<<<<<<< HEAD
        // Generar codigo de reserv


        DTReservaGrupal* nuevaReservaGrupal = new DTReservaGrupal(grupal->getCheckIn(), grupal->getCheckOut(),EstadoReserva(0), grupal->getHabitacion(), grupal->getHuespedes());

        // Agregar la reserva a la lista de reservas
    } 
 else {
=======
        // Crear nueva reserva grupal
        DTReserva* dtReserva = new DTReserva(grupal->getCheckIn(), grupal->getCheckOut(), 0, grupal->getHabitacion());

        // Agregar la reserva a la lista de reservas
        reservas.push_back(dtReserva);
    }  else {
>>>>>>> 23fa48b (funcion registro:Reserva Grupal)
        throw std::invalid_argument("Tipo de reserva desconocido.");
    }
}
=======

>>>>>>> c071f8b (Algunos cambios a los nombres)
    
    
};

#endif
