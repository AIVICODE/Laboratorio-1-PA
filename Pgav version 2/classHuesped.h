#ifndef CLASSHUESPED_H
#define CLASSHUESPED_H

#include <string>

class Huesped {
public:
    Huesped(std::string nombre, std::string email, bool esFinger);

    std::string getNombre() const;
    std::string getEmail() const;
    bool esFinger() const;

private:
    std::string nombre_;
    std::string email_;
    bool esFinger_;
};

Huesped::Huesped(std::string nombre, std::string email, bool esFinger) :
        nombre_(nombre),
        email_(email),
        esFinger_(esFinger)
{}

std::string Huesped::getNombre() const {
    return nombre_;
}

std::string Huesped::getEmail() const {
    return email_;
}

bool Huesped::esFinger() const {
    return esFinger_;
}
#endif