#ifndef SYSTEMA_H
#define SYSTEMA_H
#include <list>
#include <string>
#include <vector>
#include "DTHuesped.h"
#include "classHabitacion.h"
#include "DTHabitacion.h"
#include "DTreserva.h"
#include "define.h"
#include "classHuesped.h"
#include "DTReservaIndividual.h"
#include "DTREservaGrupal.h"
#include "classReserva.h"
#include "classReservaIndividual.h"
#include "classReservaGrupal.h"

class Systema {
private:
    std::vector<Huesped*> huespedes;
    std::vector<Habitacion*> habitaciones;
    std::vector<Reserva*> reservas;

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
        Huesped* nuevoHuesped = new Huesped(nombre, email, esFinger);
        huespedes.push_back(nuevoHuesped);
    }

    void agregarHabitacion(int numero, float precio, int capacidad) {
        for (auto habitacion : habitaciones) {
            if (habitacion->getNumero() == numero) {
                throw std::invalid_argument("Ya existe una habitacion registrada con el mismo numero.");
            }
        }
        Habitacion* nuevaHabitacion = new Habitacion(numero, precio, capacidad);
        habitaciones.push_back(nuevaHabitacion);
    }

DTHuesped** obtenerHuespedes(int& cantHuespedes) {
    cantHuespedes = huespedes.size();
    DTHuesped** listaHuespedes = new DTHuesped*[cantHuespedes];
    for (int i = 0; i < cantHuespedes; i++) {
        listaHuespedes[i] = new DTHuesped(huespedes[i]->getNombre(), huespedes[i]->getEmail(), huespedes[i]->esFinger());
    }
    return listaHuespedes;
}

    DTHabitacion** obtenerHabitaciones(int& cantHabitaciones) {
        cantHabitaciones = habitaciones.size();
        DTHabitacion** listaHabitaciones = new DTHabitacion*[cantHabitaciones];
        for (int i = 0; i < cantHabitaciones; i++) {
            listaHabitaciones[i] = new DTHabitacion(habitaciones[i]->getNumero(),habitaciones[i]->getPrecio(),habitaciones[i]->getCapacidad());
        }
        return listaHabitaciones;
    }
        void registrarReserva(std::string email, DTReserva* reserva) {
    // Buscamos el huesped correspondiente al email dado en la lista de huespedes del sistema
    Huesped* dtHuesped = nullptr;
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
    Habitacion* dtHabitacion = nullptr;
    for (auto habitacion : habitaciones) {
        if (habitacion->getNumero() == reserva->getHabitacion()) {
            dtHabitacion = habitacion;
            break;
        }
    }
    if (dtHabitacion == nullptr) {
        throw std::invalid_argument("La habitacion no esta registrada en el sistema.");
    }
   if (DTReservaIndividual* individual = dynamic_cast<DTReservaIndividual*>(reserva)) {
    // Manejar la reserva individual
    Reserva* nuevaReservaIndividual = new ReservaIndividual(individual->getCheckIn(), individual->getCheckOut(), individual->getEstado(),dtHabitacion,dtHuesped,individual ->getPagado());
    cout<<individual->getPagado();
    reservas.push_back(nuevaReservaIndividual); // Agregar la reserva individual al vector de reservas
    cout<<"agrega";
} else if (DTReservaGrupal* grupal = dynamic_cast<DTReservaGrupal*>(reserva)) {
    // Manejar la reserva grupal

if (grupal->getHuespedes().size() <= 1) {
        throw std::invalid_argument("La reserva grupal debe tener al menos dos huespedes.");
    }
    std::vector<DTHuesped> huespedes = grupal->getHuespedes();

// Crear un vector de punteros a DTReserva
std::vector<Huesped> grupalh;

// Recorrer los huéspedes y crear objetos DTReserva con los atributos de cada huésped
for (const auto& huesped : huespedes) {
    // Obtener los atributos del huésped
    std::string nombre = huesped.getNombre();
    std::string email = huesped.getEmail();
    bool esteckno=huesped.getEsFinger();
    // Crear un objeto DTReserva con los atributos del huésped
    Huesped huesped3s = Huesped(nombre, email, esteckno);

    // Agregar el puntero al objeto DTReserva al vector grupalh
    grupalh.push_back(huesped3s);
}

    Reserva* nuevaReservaGrupal = new ReservaGrupal(grupal->getCheckIn(), grupal->getCheckOut(),EstadoReserva(0),dtHabitacion,dtHuesped, grupalh);
    reservas.push_back(nuevaReservaGrupal); // Agregar la reserva grupal al vector de reservas
    } 
 else {
        throw std::invalid_argument("Tipo de reserva desconocido.");
    }
    
}



 DTReserva** obtenerReservas(DTFecha fecha, int& cantReservas) {
    // Creamos un arreglo de DTReserva** con el tamaño máximo posible
    DTReserva** resultado = new DTReserva*[reservas.size()];
    cout<<reservas.size();
    cantReservas = 0;
    // Copiamos las reservas correspondientes al arreglo y contamos la cantidad de reservas
    for (auto reserva : reservas) {
        cout << "entra a for";
        if (reserva->getCheckIn() <= fecha && reserva->getCheckOut() >= fecha) {
            cout << "entra por positivo";
            if (ReservaIndividual* ind = dynamic_cast<ReservaIndividual*>(reserva)) {
                resultado[cantReservas] = new DTReservaIndividual(ind->getCheckIn(),ind->getCheckOut(),ind->getEstado(),ind->getNumeroHabitacion(),ind->calcularCosto(),ind->getPagado());
                cantReservas++;
            } else if (ReservaGrupal* grup = dynamic_cast<ReservaGrupal*>(reserva)) {
                std::vector<Huesped> huespedes2 = grup->getHuespedes();

std::vector<Huesped> huespedes = grup->getHuespedes();

// Crear un vector de punteros a DTReserva
std::vector<DTHuesped> grupalh;

// Recorrer los huéspedes y crear objetos DTReserva con los atributos de cada huésped
for (const auto& huesped : huespedes) {
    // Obtener los atributos del huésped
    std::string nombre = huesped.getNombre();
    std::string email = huesped.getEmail();
    bool esteckno=huesped.esFinger();
    // Crear un objeto DTReserva con los atributos del huésped
    DTHuesped huesped3s = DTHuesped(nombre, email, esteckno);

    // Agregar el puntero al objeto DTReserva al vector grupalh
    grupalh.push_back(huesped3s);
}
                resultado[cantReservas] = new DTReservaGrupal(grup->getCheckIn(),grup->getCheckOut(),grup->getEstado(),grup->getNumeroHabitacion(),grup->calcularCosto(),grupalh);
                cantReservas++;
            }
        }
    }
    cout<<cantReservas;
    
    return resultado;
 }
};
#endif