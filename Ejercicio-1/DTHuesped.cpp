#include "DTHuesped.h"

// Constructor
DTHuesped::DTHuesped(std::string nombre, std::string email, bool esFinger) {
    // Constructor de DTHuesped
    // Asignar los valores de los parámetros a los miembros de datos correspondientes
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
}

// Getters
std::string DTHuesped::getNombre() const {
    return nombre;
}

std::string DTHuesped::getEmail() const {
    return email;
}

bool DTHuesped::getEsFinger() const {
    return esFinger;
}

// Setters
void DTHuesped::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void DTHuesped::setEmail(std::string email) {
    this->email = email;
}

void DTHuesped::setEsFinger(bool esFinger) {
    this->esFinger = esFinger;
}