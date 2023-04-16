#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include "DTreserva.h"
#include "DTReservaIndividual.h"
#include "DTREservaGrupal.h"
#include "DTFecha.h"

std::ostream& operator<<(std::ostream& os, const DTFecha& fecha);

std::ostream& operator<<(std::ostream& os, const DTReserva& reserva);

#endif // MYOPERATORS_H
