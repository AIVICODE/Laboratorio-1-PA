#include <iostream>
#include "DTReservaGrupal.h"
    DTReservaGrupal::getHuespedes() const { return huespedes; }
    DTReservaGrupal::setHuespedes(const std::vector<DTHuesped*>& huespedes) { this->huespedes = huespedes; }
    DTReservaGrupal::ReservaGrupal();
