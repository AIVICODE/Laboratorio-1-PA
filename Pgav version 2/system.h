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
    //cout<<individual->getPagado();
    reservas.push_back(nuevaReservaIndividual); // Agregar la reserva individual al vector de reservas
} else if (DTReservaGrupal* grupal = dynamic_cast<DTReservaGrupal*>(reserva)) {
    // Manejar la reserva grupal

if (grupal->getHuespedes().size() <= 1) {
        throw std::invalid_argument("La reserva grupal debe tener al menos dos huespedes validos registrados.");
    }

std::vector<DTHuesped> huespedes1 = grupal->getHuespedes();

std::vector<Huesped*> grupalh;

// Recorrer los huéspedes y buscar coincidencias en el vector de punteros a Huesped*
for (const auto& huesped : huespedes1) {
    std::string nombre = huesped.getNombre();
    std::string email = huesped.getEmail();
    bool esteckno = huesped.getEsFinger();
    bool found = false; // Variable para indicar si se encuentra coincidencia
    // Recorrer el vector de punteros a Huesped*
    for (const auto& huespedPtr : huespedes) {
        // Comparar nombre y email del huesped con el contenido de huespedes*
        if (nombre == huespedPtr->getNombre() && email == huespedPtr->getEmail() && huespedPtr->esFinger() == esteckno) {
            found = true; // Coincidencia encontrada
            grupalh.push_back(huespedPtr); // Agregar puntero a grupalh
            break; // Salir del bucle
        }
    }

    if (!found) {
        // No se encontró coincidencia, mostrar error
        std::cout << "Error: No se encontró coincidencia para el huésped con nombre: " << nombre << " y email: " << email << std::endl;
        getchar();
        std::cout << "Presiona Enter para continuar..." << std::endl;
        // Leer una línea en blanco (hasta que se presione Enter)
        std::string entrada;
        std::getline(std::cin, entrada);

        return;
    }
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
    cantReservas = 0;
    // Copiamos las reservas correspondientes al arreglo y contamos la cantidad de reservas
    for (auto reserva : reservas) {
        if (reserva->getCheckIn() <= fecha && reserva->getCheckOut() >= fecha) {
            if (ReservaIndividual* ind = dynamic_cast<ReservaIndividual*>(reserva)) {
                resultado[cantReservas] = new DTReservaIndividual(ind->getCheckIn(),ind->getCheckOut(),ind->getEstado(),ind->getNumeroHabitacion(),ind->calcularCosto(),ind->getPagado());
                cantReservas++;
            } else if (ReservaGrupal* grup = dynamic_cast<ReservaGrupal*>(reserva)) {
                std::vector<DTHuesped> grupalh;
                int contteck = 0; // Agregamos la inicialización del contador contteck a 0

                // Recorrer los huéspedes y crear objetos DTHuesped con los atributos de cada huésped
                for (const auto& huesped : grup->getHuespedes()) {
                    std::string nombre = huesped->getNombre(); // Corregimos el acceso a los atributos del puntero a Huesped
                    std::string email = huesped->getEmail(); // Corregimos el acceso a los atributos del puntero a Huesped
                    bool esteckno = huesped->esFinger(); // Corregimos el acceso a los atributos del puntero a Huesped
                    if (esteckno == true) {
                        contteck++; // Contamos los huéspedes tecknopackers para el descuento
                    }
                    DTHuesped huesped3s = DTHuesped(nombre, email, esteckno);
                    grupalh.push_back(huesped3s); // Agregamos el objeto DTHuesped al vector grupalh
                }

                float costo = grup->calcularCosto();
                if (contteck >= 2) {
                    costo = costo * 0.7; // Aplicamos el descuento del 30% si hay al menos 2 huéspedes tecknopackers
                }

                resultado[cantReservas] = new DTReservaGrupal(grup->getCheckIn(),grup->getCheckOut(),grup->getEstado(),grup->getNumeroHabitacion(),costo,grupalh);
                cantReservas++;
            }
        }
    }
    return resultado;
}

};
#endif