#include <iostream>
#include <string>
#include <stdexcept>
#include "EstadoReserva.h"
#include "system.h"


using namespace std;

int main() {
    Systema systema;

    bool salir = false;
    while (!salir) {
        cout << "Bienvenido al sistema de gestión de hostel" << endl;
        cout << "1. Agregar Huesped" << endl;
        cout << "2. Agregar Habitación" << endl;
        cout << "3. Obtener Huéspedes" << endl;
        cout << "4. Obtener Habitaciones" << endl;
        cout << "5. Registrar Reserva" << endl;
        cout << "6. Obtener Reservas" << endl;
        cout << "7. Salir" << endl;

        int opcion;
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese el nombre del huésped: ";
                string nombre;
                cin >> nombre;

                cout << "Ingrese el email del huésped: ";
                string email;
                cin >> email;

                cout << "El huésped es tecnopacker? (1: si / 0: no): ";
                bool esFinger;
                cin >> esFinger;

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
                cout << "Ingrese numero de habitacion: ";
                cin >> numero;
                cout << "Ingrese precio de la habitacion: ";
                cin >> precio;
                cout << "Ingrese capacidad de la habitacion: ";
                cin >> capacidad;
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
                cout << "Ingrese email: "<<endl;
                cin >> mail;

                cout << "Ingrese fecha CheckIn formato DD,MM,AAAA: "<<endl;
                cin >> dia;
                cin >> mes;
                cin >> ano;

                cout << "Ingrese fecha CheckOut formato DD,MM,AAAA: "<<endl;
                cin >> dia_;
                cin >> mes_;
                cin >> ano_;


                cout<< "Ingrese numero de habitacion"<<endl;
                cin >> habitacion;

                cout << "Su habitacion es 1)individual o 2) grupal?"<<endl;
                cin >> option;
               if (option==1)
               {
                bool pago;
                int cond;
                cout<<"Pago la reserva? 1)si 2)no"<<endl;
                cin >> cond;
                if(cond==1){
                    pago=true;
                }else{
                    pago=false;
                }
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
    }

    return 0;
}
