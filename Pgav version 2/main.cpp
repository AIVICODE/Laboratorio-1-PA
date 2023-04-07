#include <iostream>
#include <string>
#include <stdexcept>
#include "datatypeEstadoReserva.h"
#include "system.h"


using namespace std;

int main() {
    Systema systema;
    bool loop = false;
    bool salir = false;
    int input=0;

    while (!salir) {
        cout << endl;
        cout << "<< Bienvenido al sistema de gestión de hostel >>" << endl;
        cout << "1. Agregar Huesped" << endl;
        cout << "2. Agregar Habitación" << endl;
        cout << "3. Obtener Huéspedes" << endl;
        cout << "4. Obtener Habitaciones" << endl;
        cout << "5. Registrar Reserva" << endl;
        cout << "6. Obtener Reservas" << endl;
        cout << "7. Salir" << endl;

        int opcion;
        cout << "Ingrese la opción deseada > ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: {
                
                do{
                    loop = false;
                    
                    cout << "Ingrese el nombre del huésped: ";
                    string nombre;
                    cin >> nombre;

                    cout << "Ingrese el email del huésped: ";
                    string email;
                    cin >> email;

                    bool esFinger;
                    do{
                        loop = false;
                        cout << "El huésped es tecnopacker? (1: si / 0: no): ";
                        cin >> input;
                        switch(input){
                            case 1:
                                esFinger = 1;
                                break;
                            case 0:
                                esFinger = 0;
                                break;
                            default:
                                cout << "Error, valor no incluido en las opciones dadas." << endl;
                                loop = true;
                                break;
                        }
                    }while(loop == true);
                    
                    cout << endl;
                    cout << "Huesped: " << nombre << endl;
                    cout << "Email: " << email << endl;
                    cout << "Tecnopacker: ";
                    if(esFinger == 1){
                        cout << "si" << endl;
                    }
                    else{
                         cout << "no" << endl;
                    }
                    cout << "¿Estos datos son correctos? (1: si / 0: no) :";
                    cin >> input;
                    switch(input){
                            case 1:
                                break;
                            case 0:
                                loop = true;
                                break;
                            default:
                                cout << "Error al agregar huésped" << endl;
                                loop = true;
                                break;
                        }
                    
                }while(loop == true);
                try {
                    systema.agregarHuesped(nombre, email, esFinger);
                    cout << "Huésped agregado correctamente" << endl;
                } catch (invalid_argument& e) {
                    cout << "Error al agregar huésped: " << e.what() << endl;
                }

                break;
            }

            case 2: {
                int numero, capacidad;
                float precio;
                do{
                    loop = false;
                    cout << "Ingrese numero de habitacion: ";
                    cin >> numero;
                    cout << "Ingrese precio de la habitacion: ";
                    cin >> precio;
                    cout << "Ingrese capacidad de la habitacion: ";
                    cin >> capacidad;
                    
                    cout << "Nro de Habitación: " << numero << endl;
                    cout << "Precio de Habitación: " << precio << endl;
                    cout << "Capacidad de Habitación: " << capacidad << endl;
                    cout << "¿Son estos datos correctos? (1: si / 0: no) :";
                    cin >> input; 
                    switch(input){
                            case 1:
                                break;
                            case 0:
                                loop = true;
                                break;
                            default:
                                cout << "Error al agregar Habitación, Vuelva a ingresar los datos." << endl;
                                loop = true;
                                break;
                        }
               }while(loop == true);
                try {
                    systema.agregarHabitacion(numero, precio, capacidad);
                    cout << "Habitacion agregada exitosamente." << endl;
                } catch(invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }

            case 3: {
                int cantHuespedes = 0;
                DTHuesped** huespedes = systema.obtenerHuespedes(cantHuespedes);
                for(int i = 0; i < cantHuespedes; i++) {
                    cout << "Huesped " << i+1 << ":" << endl;
                    cout << "Nombre: " << huespedes[i]->getNombre() << endl;
                    cout << "Email: " << huespedes[i]->getEmail() << endl;
                    if(huespedes[i]->getEsFinger())
                        cout << "Tiene es Tecnopacker" << endl;
                    else
                        cout << "No tiene Tecnopacker" << endl;
                    delete huespedes[i];
                }
                delete[] huespedes;
                break;
                break;
            }

            case 4: {
                 int cantHabitaciones = 0;
                DTHabitacion** habitaciones = systema.obtenerHabitaciones(cantHabitaciones);
                for(int i = 0; i < cantHabitaciones; i++) {
                    cout << "Habitacion " << i+1 << ":" << endl;
                    cout << "Numero: " << habitaciones[i]->getNumero() << endl;
                    cout << "Precio: " << habitaciones[i]->getPrecio() << endl;
                    cout << "Capacidad: " << habitaciones[i]->getCapacidad() << endl;
                    delete habitaciones[i];
                }
                delete[] habitaciones;
                break;
            }

            case 5: {
                 string mail;
                 int codigo=0,dia,mes,ano,dia_,mes_,ano_,estado_,habitacion;
                float precio;
                int option;
                bool pago;
                do{
                    loop=false;
                    cout << "Ingrese email: "<<endl;
                    cin >> mail;

                    do{
                        loop = false;
                        cout << "Ingrese fecha Check-In formato DD/MM/AAAA: "<<endl;
                        cin >> ano;
                        dia = strtok(ano,"-,/ \()");
                        mes = strtok(ano,"-,/ \()");
                        if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1500 || ano > 3500){
                            loop = true;
                            cout << "Error al ingresar la fecha de Check-In" << endl;
                        }
                    }while(loop == true);

                    do{
                        loop = false;
                        cout << "Ingrese fecha Check-Out formato DD/MM/AAAA: "<<endl;
                        cin >> ano_;
                        dia_ = strtok(ano_,"-,/ \()");
                        mes_ = strtok(ano_,"-,/ \()");
                        if(dia_ < 1 || dia_ > 31 || mes_ < 1 || mes_ > 12 || ano_ < 1500 || ano_ > 3500){
                            loop = true;
                            cout << "Error al ingresar la fecha de Check-Out" << endl;
                        }
                    }while(loop == true);

                    cout<< "Ingrese numero de habitacion"<<endl;
                    cin >> habitacion;
                    do{
                        loop = false;
                        cout << "Su habitacion es 1)individual o 2) grupal?"<<endl;
                        cin >> option;
                        switch(option){
                            case 1:
                            case 2:
                                break;
                            default:
                                loop = true;
                                cout << "Error, opcion ingresada no es valida" << endl;
                                break;
                        }
                    }while(loop = true);
                    bool pago;
                    int cond;
                    do{
                        loop = false;
                        cout << "Pago la reserva? 1)si 2)no" << endl;
                        cin >> cond;
                        switch(cond){
                            case 1:
                                pago = true;
                                break;
                            case 2:
                                pago = false;
                                break;
                            default:
                                cout << "El valor ingresado no es valido, Vuelva a ingresar el dato" << endl;
                                loop = true;
                        }
                    }while(loop == true);

                    cout << "Email: " << mail << endl;
                    cout << "Fecha de Check-In: " << dia << "/" << mes << "/" << ano << endl;
                    cout << "Fecha de Check-Out: " << dia_ << "/" << mes_ << "/" << ano_ << endl;
                    cout << "Nro de Habitación: " << habitacion << endl;
                    cout << "Tipo: ";
                    if(option == 1){
                        cout << "Individual" << endl;
                        if(cond == 1){
                            cout << "Reserva pagada" << endl;
                        }
                        else{
                            cout << "Reserva no pagada" << endl;
                        }
                    }
                    else{
                        cout << "Grupal" << endl;
                    }
                    cout << "¿Son estos datos correctos? (1: si / 0: no) :";
                    cin >> input;
                    switch(input){
                        case 1:
                            break;
                        case 0:
                            loop = true;
                            break;
                        default:
                            cout << "Error al registrar la reserva" << endl;
                            loop = true;
                            break;
                    }  
                }while(loop == true);
                if (option==1){
                    try {
                        systema.registrarReserva(mail, new DTReservaIndividual(codigo, DTFecha(dia,mes,ano), DTFecha(dia_,mes_,ano_), EstadoReserva(0), habitacion,pago));
                        cout << "Reserva agregada" << endl;
                        codigo++;
                    } catch(invalid_argument& e) {
                        cout << "Error: " << e.what() << endl;
                    }
               }else{
                try {
                        std::vector<DTHuesped*> ingresanHuespedes;
                        
                        bool agregar=true;
                        do {
                            std::string nombre, email;
                            bool tecnopacker;

                            std::cout << "Ingrese el nombre del huesped "<< ": "<<endl;
                            std::cin >> nombre;
                            std::cout << "Ingrese el email del huesped " << ": "<<endl;
                            std::cin >> email;
                            std::cout << "Es tecnopacker? (0 para No, 1 para Sí): "<<endl;
                            std::cin >> tecnopacker;
                            std::cout << "Desea agregar otro? (0 para No, 1 para Sí): "<<endl;
                            std::cin >> agregar;

                        }while(agregar!=0);


                    systema.registrarReserva(mail, new DTReservaGrupal(1, DTFecha(dia,mes,ano), DTFecha(2,2,2002), EstadoReserva(0), 1,ingresanHuespedes));
                    cout << "Reserva agregada" << endl;
                    codigo++;
                } catch(invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
               }
               
                
            
                break;
            }

            case 6: {
                // Lógica para obtener reservas
                break;
            }

            case 7: {
                salir = true;
                break;
            }

            default: {
                cout << "Opción inválida, por favor intente de nuevo" << endl;
                break;
            }
        }    
    cout << endl;
    }

    return 0;
}
