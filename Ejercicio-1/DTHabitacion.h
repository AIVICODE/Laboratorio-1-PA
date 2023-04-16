#ifndef DATATYPEDTHABITACION_H
#define DATATYPEDTHABITACION_H

class DTHabitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    DTHabitacion(int numero, float precio, int capacidad);

int getNumero();
float getPrecio() ;
int getCapacidad() ;
};
#endif
