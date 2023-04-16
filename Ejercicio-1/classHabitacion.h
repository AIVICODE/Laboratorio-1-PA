#ifndef CLASSHABITACION_H
#define CLASSHABITACION_H

class Habitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    // Constructor
    Habitacion(int numero, float precio, int capacidad) ;

    // Getters
    int getNumero()const;

    float getPrecio() const;
    

    int getCapacidad() const ;

    // Setters
    void setNumero(int numero);

    void setPrecio(float precio) ;

    void setCapacidad(int capacidad) ;
    
};

#endif
