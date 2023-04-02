#include "DTFecha.h"
#include "EstadoReserva.h"
int getcodigo();
DTFecha getcheckIn();
DTFecha getchechOut();
EstadoReserva getestado();

int setcodigo(int nuevo_codigo); //retorna 0: todo bien; retorna algo diferente a 0: error
int setcheckIn(DTFecha nuevo_checkin);
int setchechOut(DTFecha nuevo_checkout);
int setestado(EstadoReserva nuevo_estado);
