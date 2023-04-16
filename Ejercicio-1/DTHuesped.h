#ifndef DATATYPEDTHUESPED_H
#define DATATYPEDTHUESPED_H
#include <string>
class DTHuesped {
private:
    std::string nombre;
    std::string email;
    bool esFinger;
public:
    // Constructor
    DTHuesped(std::string nombre, std::string email, bool esFinger);

    // Getters
    std::string getNombre() const ;

    std::string getEmail() const ;

    bool getEsFinger() const ;

    // Setters
    void setNombre(std::string nombre);

    void setEmail(std::string email) ;

    void setEsFinger(bool esFinger) ;
};

#endif
