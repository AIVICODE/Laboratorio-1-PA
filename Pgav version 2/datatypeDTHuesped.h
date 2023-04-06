#ifndef DATATYPEDTHUESPED_H
#define DATATYPEDTHUESPED_H

#include <iostream>
using namespace std;
class DTHuesped {
private:
    std::string nombre;
    std::string email;
    bool esFinger;
public:
    // Constructor
    DTHuesped(std::string nombre, std::string email, bool esFinger);
    // Getters
    std::string getNombre() const;
    std::string getEmail() const;
    bool getEsFinger() const;
    // Setters
    void setNombre(std::string nombre);
    void setEmail(std::string email);
    void setEsFinger(bool esFinger);
};

// Constructor
DTHuesped::DTHuesped(std::string nombre, std::string email, bool esFinger) {
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

#endif
