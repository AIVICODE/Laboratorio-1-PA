#include "DTReserva.h"
DTReserva::~DTReserva() {}
DTReserva::getCodigo() const { return codigo; }
DTReserva::getCheckIn() const { return checkIn; }
DTReserva::getCheckOut() const { return checkOut; }
DTReserva::getEstado() const { return estado; }
DTReserva::getCosto() const { return costo; }
DTReserva::getHabitacion() const { return habitacion; }
DTReserva::setEstado(EstadoReserva estado) { this->estado = estado; }
DTReserva::setCosto(float costo) { this->costo = costo; }
DTReserva::setHabitacion(int numHabitacion) {
    this->habitacion = numHabitacion;
}
DTReserva::setCheckIn(DTFecha checkIn) { this->checkIn = checkIn; }
