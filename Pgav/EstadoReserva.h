#ifndef ESTADORESERVA_H
#define ESTADORESERVA_H


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


#endif
