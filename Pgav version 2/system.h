#ifndef SYSTEMA_H
#define SYSTEMA_H
#include <list>
#include <string>
#include <vector>
#include "datatypeDTHuesped.h"
#include "datatypeDTHabitacion.h"
#include "datatypeDTreserva.h"
#include "define.h"
#include "classHuesped.h"
#include "datatypeDTReservaIndividual.h"
#include "datatypeDTREservaGrupal.h"

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
        DTReserva* nuevareserva = new DTReserva(reserva->getCodigo(),reserva->getCheckIn(),reserva->getCheckOut(),reserva->getEstado(),reserva->getHabitacion());
        reservas.push_back(nuevareserva);
    
        }
    
};

#endif