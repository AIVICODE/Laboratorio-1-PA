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
    Systema();

    ~Systema();

    void agregarHuesped(std::string nombre, std::string email, bool esFinger);

    void agregarHabitacion(int numero, float precio, int capacidad);

    DTHuesped** obtenerHuespedes(int& cantHuespedes);

    DTHabitacion** obtenerHabitaciones(int& cantHabitaciones);

    DTReserva** obtenerReservas(DTFecha fecha, int& cantReservas);

    void registrarReserva(std::string email, DTReserva* reserva);

};
#endif

 