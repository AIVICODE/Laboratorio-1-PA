#include "classHuesped.h"

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