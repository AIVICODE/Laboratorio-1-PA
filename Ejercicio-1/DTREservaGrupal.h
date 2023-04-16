#ifndef DATATYPEDTRESERVAGRUPAL_H
#define DATATYPEDTRESERVAGRUPAL_H
#include <vector>
#include <string.h>
#include "DTHuesped.h"
#include "DTFecha.h"
#include "EstadoReserva.h"
#include "DTreserva.h"
class DTReservaGrupal : public DTReserva {
private:
    std::vector<DTHuesped> huespedes;
public:
    DTReservaGrupal( DTFecha checkIn, DTFecha checkOut, EstadoReserva estado, int habitacion, float costo,std::vector<DTHuesped> huespedes)
        : DTReserva(checkIn, checkOut, estado, habitacion,costo), huespedes(huespedes) {}

    const std::vector<DTHuesped>& getHuespedes() const;
    void setHuespedes(const std::vector<DTHuesped>& huespedes);
     int getCantHuespedes() const ;
};
#endif