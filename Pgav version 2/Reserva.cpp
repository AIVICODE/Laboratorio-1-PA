#include "classReserva.h"
#include "DTFecha.h"
#include "EstadoReserva.h"

Reserva::Reserva(DTFecha checkIn, DTFecha checkOut, EstadoReserva estado) {
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->costo = 0.0;
    this->habitacion_ = nullptr;
    this->huesped_ = nullptr;
}

int Reserva::getCodigo() const {
    return this->codigo;
}

void Reserva::setCodigo(int codigo) {
    this->codigo = codigo;
}

DTFecha Reserva::getCheckIn() const {
    return this->checkIn;
}

void Reserva::setCheckIn(DTFecha checkIn) {
    this->checkIn = checkIn;
}

DTFecha Reserva::getCheckOut() const {
    return this->checkOut;
}

void Reserva::setCheckOut(DTFecha checkOut) {
    this->checkOut = checkOut;
}

EstadoReserva Reserva::getEstado() const {
    return this->estado;
}

void Reserva::setEstado(EstadoReserva estado) {
    this->estado = estado;
}

float Reserva::getCosto() const {
    return this->costo;
}

void Reserva::setCosto(float costo) {
    this->costo = costo;
}

float Reserva::calcularCosto() {
    // Implementa el cálculo del costo de la reserva
    // según la lógica de tu programa
    return 0;
}