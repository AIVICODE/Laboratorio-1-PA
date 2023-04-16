#include "operator.h"
#include <iostream>
std::ostream& operator<<(std::ostream& os, const DTFecha& fecha) {
    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio();
    return os;
}

std::ostream& operator<<(std::ostream& os, const DTReserva& reserva) {
    os << "TipoReserva: ";
    if (dynamic_cast<const DTReservaIndividual*>(&reserva)) {
        os << "Individual\n";
        const DTReservaIndividual& ind = static_cast<const DTReservaIndividual&>(reserva);
        os << "Pagado: " << (ind.getPagado() ? "Si" : "No") << std::endl;
    } else if (dynamic_cast<const DTReservaGrupal*>(&reserva)) {
        os << "Grupal\n";
        const DTReservaGrupal& grupal = static_cast<const DTReservaGrupal&>(reserva);
        os << "Huéspedes: ";
        for (const DTHuesped& huesped : grupal.getHuespedes()) {
            os << std::endl;
            os << huesped.getNombre() << " - " << huesped.getEmail();
            if (huesped.getEsFinger()) {
                os << " - es Tecnopacker";
            }
            os << ", "<<std::endl;
        }
        os << std::endl;
    }
    os << "FechaCheckIn: " << reserva.getCheckIn() << std::endl;
    os << "FechaCheckOut: " << reserva.getCheckOut() << std::endl;
    os << "Habitación: " << reserva.getHabitacion() << std::endl;
    os << "Costo: $" << reserva.getCosto() << std::endl;
    return os;
}
