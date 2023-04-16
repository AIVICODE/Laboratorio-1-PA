#include "EstadoReserva.h"

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
            throw std::invalid_argument("Valor de estado inválido");
    }
}
