#ifndef CLASSHABITACION_H
#define CLASSHABITACION_H

class Habitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    Habitacion(int numero, float precio, int capacidad);
    int getNumero() const;

    void setNumero(int numero);
    float getPrecio() const ;

    void setPrecio(float precio);

    int getCapacidad() const;

    void setCapacidad(int capacidad);
};
#endif