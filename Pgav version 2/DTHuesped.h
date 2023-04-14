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
    DTHuesped(std::string nombre, std::string email, bool esFinger) {
        // Constructor de DTHuesped
        // Asignar los valores de los parámetros a los miembros de datos correspondientes
        this->nombre = nombre;
        this->email = email;
        this->esFinger = esFinger;
    }

    // Getters
    std::string getNombre() const {
        return nombre;
    }

    std::string getEmail() const {
        return email;
    }

    bool getEsFinger() const {
        return esFinger;
    }

    // Setters
    void setNombre(std::string nombre) {
        this->nombre = nombre;
    }

    void setEmail(std::string email) {
        this->email = email;
    }

    void setEsFinger(bool esFinger) {
        this->esFinger = esFinger;
    }
};

#endif
