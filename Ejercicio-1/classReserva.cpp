#include "classReserva.h"

// Implementación de las funciones miembro de Reserva


Reserva::~Reserva() {
    // Implementación del destructor si es necesario
}

int Reserva::getCodigo() const {
    return codigo;
}

void Reserva::setCodigo(int codigo) {
    this->codigo = codigo;
}

DTFecha Reserva::getCheckIn() const {
    return checkIn;
}

void Reserva::setCheckIn(DTFecha checkIn) {
    this->checkIn = checkIn;
}

DTFecha Reserva::getCheckOut() const {
    return checkOut;
}

void Reserva::setCheckOut(DTFecha checkOut) {
    this->checkOut = checkOut;
}

EstadoReserva Reserva::getEstado() const {
    return estado;
}

void Reserva::setEstado(EstadoReserva estado) {
    this->estado = estado;
}

float Reserva::getCosto() const {
    return costo;
}

void Reserva::setCosto(float costo) {
    this->costo = costo;
}

int Reserva::getNumeroHabitacion() const {
    return habitacion_->getNumero();
}