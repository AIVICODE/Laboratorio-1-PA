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

#endif