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
            if (huesped->getEmail() == email) {
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
        if (huesped->getEmail() == email) {
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
        DTReserva* reservas = new DTReservaIndividual(individual->getCheckIn(), individual->getCheckOut(), individual->getEstado(), individual->getHabitacion(),individual ->getPagado());
    } else if (DTReservaGrupal* grupal = dynamic_cast<DTReservaGrupal*>(reserva)) {
         // Manejar la reserva grupal
        if (grupal->getHuespedes().size() <= 1) {
            throw std::invalid_argument("La reserva grupal debe tener al menos dos huespedes.");
        }


        DTReserva* reservas = new DTReservaGrupal(grupal->getCheckIn(), grupal->getCheckOut(),EstadoReserva(0), grupal->getHabitacion(), grupal->getHuespedes());

        // Agregar la reserva a la lista de reservas
    } 
 else {
        throw std::invalid_argument("Tipo de reserva desconocido.");
    }
}
 DTReserva** obtenerReservas(DTFecha fecha, int& cantReservas) {
    // Creamos un arreglo de DTReserva** con el tamaño máximo posible
    DTReserva** resultado = new DTReserva*[reservas.size()];
    cantReservas = 0;

    // Copiamos las reservas correspondientes al arreglo y contamos la cantidad de reservas
    for (auto reserva : reservas) {
        cout << "entra";
        if (reserva->getCheckIn() == fecha) {
            cout << "entra";
            if (DTReservaIndividual* ind = dynamic_cast<DTReservaIndividual*>(reserva)) {
                resultado[cantReservas] = new DTReservaIndividual(*ind);
                cantReservas++;
            } else if (DTReservaGrupal* grup = dynamic_cast<DTReservaGrupal*>(reserva)) {
                int cantHuespedes = grup->getCantHuespedes();
                DTHuesped** huespedes = new DTHuesped*[cantHuespedes];
                for (int i = 0; i < cantHuespedes; i++) {
                    huespedes[i] = new DTHuesped(grup->getHuespedes()[i]);
                }
                resultado[cantReservas] = new DTReservaGrupal(*grup);
                cantReservas++;
            }
        }
    }
    cout<<cantReservas;
    
    return resultado;
 }
};
#endif