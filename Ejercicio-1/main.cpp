#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdexcept>
#include "system.h"
#include "operator.h"


using namespace std;
// #include "system.cpp"
// #include "EstadoReserva.cpp"
// #include "DTReservaIndividual.cpp"
// #include "DTREservaGrupal.cpp"
// #include "DTreserva.cpp"
// #include "DTHuesped.cpp"
// #include "DTHabitacion.cpp"
// #include "DTFecha.cpp"
// #include "classReservaIndividual.cpp"
// #include "classReservaGrupal.cpp"
// #include "classReserva.cpp"
// #include "classHuesped.cpp"
// #include "classHabitacion.cpp"
int main() {
    Systema systema;
    bool loop = false;
    bool salir = false;
    bool seguir = true;
    char skip;
    char input;

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

        char opcion;
        cout << "Ingrese la opción deseada > ";
        cin >> opcion;
        scanf("%*[^\n]%*c");
        cout << endl;
        skip = false;
        switch (opcion) {
            case '1': {
                string nombre;
                string email;
                bool esFinger;
                do{
                    loop = false;
                    
                    cout << "Ingrese el nombre del huésped: ";
                   
                    cin >> nombre;

                    cout << "Ingrese el email del huésped: ";
                    
                    cin >> email;

                   
                    do{
                        loop = false;
                        cout << "El huésped es tecnopacker? (1: si / 0: no): ";
                        cin >> input;
                        switch(input){
                            case '1':
                                esFinger = 1;
                                break;
                            case '0':
                                esFinger = 0;
                                break;
                            default:
                                cout << "Error, valor no incluido en las opciones dadas." << endl;
                                loop = true;
                                break;
                        }
                        scanf("%*[^\n]%*c");
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
                    cout << "¿Estos datos son correctos? (1: si / 0: no / s: salir) :";
                    cin >> input;
                    switch(input){
                            case '1':
                                break;
                            case '0':
                                loop = true;
                                break;
                            case 's':
                                skip = true;
                                break;
                            default:
                                cout << "Error al agregar huésped" << endl;
                                loop = true;
                                break;
                        }
                    
                }while(loop == true);
                if(skip == false){
                    try {
                        systema.agregarHuesped(nombre, email, esFinger);
                        cout << "Huésped agregado correctamente" << endl;
                    } catch (invalid_argument& e) {
                        cout << "Error al agregar huésped: " << e.what() << endl;
                    }
                }
                scanf("%*[^\n]%*c");
                break;
            }

            case '2': {
                int numero, capacidad;
                float precio;
                stringstream numAux,numAux2,numAux3;
                string aux,aux2,aux3;
                do{
                    loop = false;
                    cout << "Ingrese numero de habitacion: ";
                    cin >> aux;
                    numAux << aux;
                    numAux >> numero;

                    scanf("%*[^\n]%*c");
                    
                    cout << "Ingrese precio de la habitacion: ";
                    cin >> aux2;
                    numAux2 << aux2;
                    numAux2 >> precio;

                    scanf("%*[^\n]%*c");

                    cout << "Ingrese capacidad de la habitacion: ";
                    cin >> aux3;
                    numAux3 << aux3;
                    numAux3 >> capacidad;
                    scanf("%*[^\n]%*c");
                    
                    cout << endl;
                    cout << "Nro de Habitación: " << numero << endl;
                    cout << "Precio de Habitación: " << precio << endl;
                    cout << "Capacidad de Habitación: " << capacidad << endl;
                    
                    cout << "¿Estos datos son correctos? (1: si / 0: no / s: salir) :";
                    cin >> input;
                    switch(input){
                            case '1':
                                break;
                            case '0':
                                loop = true;
                                break;
                            case 's':
                                skip = true;
                                break;
                            default:
                                cout << "Error al agregar Habitación, Vuelva a ingresar los datos." << endl;
                                loop = true;
                                break;
                        }
                    scanf("%*[^\n]%*c");
               }while(loop == true);
               if(skip == false){
                try {
                    systema.agregarHabitacion(numero, precio, capacidad);
                    cout << "Habitacion agregada exitosamente." << endl;
                } catch(invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
               }
                break;
            }

            case '3': {
                int cantHuespedes = 0;
                DTHuesped** huespedes = systema.obtenerHuespedes(cantHuespedes);
                if(cantHuespedes==0){
                    cout<< "no hay huespedes registrados"<<endl;
                }else{
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
                }
                delete[] huespedes;
                getchar();
                   std::cout << "Presiona Enter para continuar..." << std::endl;
                    // Leer una línea en blanco (hasta que se presione Enter)
                    std::string entrada;
                    std::getline(std::cin, entrada);

                break;
            }

            case '4': {
                 int cantHabitaciones = 0;
                DTHabitacion** habitaciones = systema.obtenerHabitaciones(cantHabitaciones);
                if(cantHabitaciones==0){
                    cout<<"no hay habitaciones registradas"<<endl;
                }else{
                for(int i = 0; i < cantHabitaciones; i++) {
                    cout << "Habitacion " << i+1 << ":" << endl;
                    cout << "Numero: " << habitaciones[i]->getNumero() << endl;
                    cout << "Precio: " << habitaciones[i]->getPrecio() << endl;
                    cout << "Capacidad: " << habitaciones[i]->getCapacidad() << endl;
                    delete habitaciones[i];
                }
                }
                delete[] habitaciones;
                getchar();
                   std::cout << "Presiona Enter para continuar..." << std::endl;
                    // Leer una línea en blanco (hasta que se presione Enter)
                    std::string entrada;
                    std::getline(std::cin, entrada);
                break;
            }

            case '5': {
                string mail;
                int dia,mes,ano,dia_,mes_,ano_,habitacion;
                float costo=0.0;
                std::vector<DTHuesped> ingresanHuespedes;
                char option;
                bool pago;
                char cond;
                string choice1;
                stringstream choice;
                bool agregar=true;
                do{
                    loop=false;
                    cout << "Ingrese email: "<<endl;
                    cin >> mail;

                        cout << "Ingrese fecha Check-In formato DD MM AAAA: "<<endl;
                        cin >> dia;
                        cin >> mes;
                        cin >> ano;

                        if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900){
                            throw invalid_argument("Formato de Fecha No Respetado");
                        }
                        scanf("%*[^\n]%*c");

                        cout << "Ingrese fecha Check-Out formato DD MM AAAA: "<<endl;
                        cin >> dia_;
                        cin >> mes_;
                        cin >> ano_;

                        if(dia_ < 1 || dia_ > 31 || mes_ < 1 || mes_ > 12 || ano_ < 1900){
                            throw invalid_argument("Formato de Fecha No Respetado");
                        }
                        scanf("%*[^\n]%*c");

                    cout<< "Ingrese numero de habitacion"<<endl;
                    cin >> choice1;
                    choice << choice1;
                    choice >> habitacion;
                    scanf("%*[^\n]%*c");
                    
                    do{
                        
                        loop = false;
                        cout << "Su habitacion es 1)individual o 2) grupal?"<<endl;
                        cin >> option;
                        switch(option){
                            case '1':
                                do{
                                    loop = false;
                                    cout << "Pago la reserva? 1)si 2)no" << endl;
                                    cin >> cond;
                                    switch(cond){
                                        case '1':
                                            pago = true;
                                            break;
                                        case '2':
                                            pago = false;
                                            break;
                                        default:
                                            cout << "El valor ingresado no es valido, Vuelva a ingresar el dato" << endl << endl;
                                            loop = true;
                                    }
                                    scanf("%*[^\n]%*c");
                                }while(loop == true);
                                break;
                            case '2':
                                do {
                                    string nombre,email;
                                    bool tecnopacker;
                                    char choice;
                                    
                                    cout << "Ingrese el nombre del huesped "<< ": "<<endl;
                                    cin >> nombre;
                                    scanf("%*[^\n]%*c");
                                    cout << "Ingrese el email del huesped " << ": "<<endl;
                                    cin >> email;
                                    scanf("%*[^\n]%*c");
                                    cout << "Es tecnopacker? (0 para No, 1 para Sí) (default = 0): "<<endl;
                                    cin >> choice;
                                    if(choice == '1'){
                                        tecnopacker = 1;
                                    }
                                    else{
                                        tecnopacker = 0;
                                    }
                                    scanf("%*[^\n]%*c");
                                    cout << "Desea agregar otro? (0 para No, 1 para Sí): "<<endl;
                                    cin >> choice;
                                    if(choice == '0'){
                                        agregar = 0;
                                    }
                                    scanf("%*[^\n]%*c");
                                    DTHuesped huesped3s = DTHuesped(nombre, email,tecnopacker);
                                    ingresanHuespedes.push_back(huesped3s);

                                }while(agregar!=0);

                                break;
                            default:
                                loop = true;
                                cout << "Error, opcion ingresada no es valida" << endl;
                                break;
                        }
                        scanf("%*[^\n]%*c");
                    }while(loop == true);
                }while(loop == true);
                if(seguir == true){
                    if (option == '1'){
                        try {
                            systema.registrarReserva(mail, new DTReservaIndividual(DTFecha(dia,mes,ano), DTFecha(dia_,mes_,ano_), EstadoReserva(0), habitacion,costo,pago));
                            cout << "Reserva agregada" << endl;
                        } catch(invalid_argument& e) {
                            cout << "Error: " << e.what() << endl;
                        }
                    }else{
                        try {
                            systema.registrarReserva(mail, new DTReservaGrupal(DTFecha(dia,mes,ano), DTFecha(dia_,mes_,ano_), EstadoReserva(0), habitacion,costo,ingresanHuespedes));
                        } catch(invalid_argument& e) {
                            cout << "Error: " << e.what() << endl;
                        }
                    }
                }
                    cout << endl;
                   std::cout << "Presiona Enter para continuar..." << std::endl;
                    // Leer una línea en blanco (hasta que se presione Enter)
                    std::string entrada;
                    std::getline(std::cin, entrada);
            
                break;
            }

            case '6': {
                std::vector<DTReserva*> reservas;
                int cantReservas;
                int dia1,mes1,ano1;
            
                    
                    cout << "Ingrese fecha a buscar [formato DD MM AAAA]: "<<endl;
                    cin >> dia1;
                    cin >> mes1;
                    cin >> ano1;

                    if(dia1 < 1 || dia1 > 31 || mes1 < 1 || mes1 > 12 || ano1 < 1900){
                        throw invalid_argument("Formato No Respetado");
                    }
                    cout << endl;
                    
                DTReserva** res = systema.obtenerReservas(DTFecha(dia1,mes1,ano1), cantReservas);
                for (int i = 0; i < cantReservas; i++) {
                DTReserva* r = dynamic_cast<DTReserva*>(res[i]);
                std::cout << *r << std::endl;
                }
                delete[] res;
    
                    getchar();
                   std::cout << "Presiona Enter para continuar..." << std::endl;
                    // Leer una línea en blanco (hasta que se presione Enter)
                    std::string entrada;
                    std::getline(std::cin, entrada);
                break;
            }

            case '7': {
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
