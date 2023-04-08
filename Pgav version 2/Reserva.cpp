#include "classReserva.h"

Reserva::Reserva(int codigo, DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, Habitacion* habitacion)
    : codigo(codigo), checkIn(checkIn), checkOut(checkOut), estado(estado), habitacion_(habitacion) {
    calcularCosto();
}

Reserva::~Reserva() {}

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
    calcularCosto();
}

DTFecha Reserva::getCheckOut() const {
    return checkOut;
}

void Reserva::setCheckOut(DTFecha checkOut) {
    this->checkOut = checkOut;
    calcularCosto();
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

float Reserva::calcularCosto() {
    int cantDias = checkOut - checkIn; // suponiendo que se sobrecargó el operador "-" para fechas
    costo = cantDias * habitacion_->getPrecio(); // obteniendo el precio de la habitación a través del getter
    return costo;
}