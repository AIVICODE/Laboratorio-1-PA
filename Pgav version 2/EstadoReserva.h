#ifndef DATATYPESTADORESERVA_H
#define DATATYPESTADORESERVA_H

#include <stdexcept>

class EstadoReserva {
public:
    enum Reserva {
        Abierta,
        Cerrada,
        Cancelada
    };

    EstadoReserva(int estado);

private:
    Reserva estado_;
};

EstadoReserva::EstadoReserva(int estado) {
    switch (estado) {
        case 0:
            estado_ = Abierta;
            break;
        case 1:
            estado_ = Cerrada;
            break;
        case 2:
            estado_ = Cancelada;
            break;
        default:
            throw std::invalid_argument("Estado de reserva inválido.");
    }
}

#endif
