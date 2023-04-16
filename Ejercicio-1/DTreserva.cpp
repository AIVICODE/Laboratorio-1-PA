#include "DTreserva.h"



// Destructor
DTReserva::~DTReserva() {}

// Métodos Getters
int DTReserva::getCodigo() const {
    return codigo;
}

DTFecha DTReserva::getCheckIn() const {
    return checkIn;
}

DTFecha DTReserva::getCheckOut() const {
    return checkOut;
}

EstadoReserva DTReserva::getEstado() const {
    return estado;
}

float DTReserva::getCosto() const {
    return costo;
}

int DTReserva::getHabitacion() const {
    return habitacion;
}

// Métodos Setters
void DTReserva::setEstado(EstadoReserva estado) {
    this->estado = estado;
}

void DTReserva::setCosto(float costo) {
    this->costo = costo;
}

void DTReserva::setHabitacion(int numHabitacion) {
    this->habitacion = numHabitacion;
}

void DTReserva::setCheckIn(DTFecha checkIn) {
    this->checkIn = checkIn;
}

void DTReserva::setCheckOut(DTFecha checkOut) {
    this->checkOut = checkOut;
}