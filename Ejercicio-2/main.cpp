#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;

vector<A*> _A_;
vector<B*> _B_;
vector<C*> _C_;

#define MAX_GRUPOS  100

void Mostrar_menu();

void Agregar();
void Eliminar();
void Mostrar();
void Modificar();

int main(){
	_A_.reserve(MAX_GRUPOS);
	_B_.reserve(MAX_GRUPOS);
	_C_.reserve(MAX_GRUPOS);
	int opcion;
	bool continuar_bucle=true;
	while(continuar_bucle){
		Mostrar_menu();
		cin >> opcion;
		switch(opcion){
			case 1:
				Agregar();
				break;
			case 2:
				Eliminar();
				break;
			case 3:
				Modificar();
				break;
			case 4:
				Mostrar();
				break;
			case 5:
				cout << "Adíos" << endl;
				continuar_bucle=false;
				break;
			default:
				
				cout << "Opción invalida" << endl;
		
		}
	

	}
	return 0;
}

void Mostrar_menu(){
	cout << "Menu Principal" << endl;
	cout << "---------------------"<< endl;
	cout << "1) Agregar grupo." << endl;
	cout << "2) Eliminar grupo." << endl;
	cout << "3) Modifiar grupo." << endl;
	cout << "4) Mostrar grupos." << endl;
	cout << "5) Salir." << endl;

}

void Agregar(){
	if (_C_.size() == MAX_GRUPOS){
		cout << "Error: ya se alcansó el limite de grupos" << endl;
		return;
	}
	int a,b,c;
	bool opcion;
	cout << "Ingrese el valor de A: ";
	cin >> a;
	cout << "Ingrese el valor de B: ";
	cin >> b;
	cout << "Ingrese al valor de C: ";
	cin >> c;

	cout << "Los valores ingresados son: " << endl;
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "C: " << c << endl;
	cout << "¿Son estos valores correctos? (0: si; *: no)" << endl;
	cin >> opcion;
	if (opcion == 0){
		//Se crean los objetos y se añaden a los vectores
		A * nueva_A = new A(a);
		B * nueva_B = new B(b);
		C * nueva_C = new C(c);

		nueva_A->link(nueva_B);
		nueva_A->link(nueva_C);
		nueva_B->link(nueva_A);
		nueva_B->link(nueva_C);
		nueva_C->link(nueva_A);
		nueva_C->link(nueva_B);

		_A_.push_back(nueva_A);
		_B_.push_back(nueva_B);
		_C_.push_back(nueva_C);


	}
	cout << endl;
}

void Eliminar(){
	int id,contador = 0;
	cout << "Ingrese el id del grupo a eliminar: ";
	cin >> id;
	cout << endl;

	for (auto _a_ : _A_){
		if (contador == id){
			delete _a_->b();
			delete _a_->c();
			delete _a_;
			_A_.erase(_A_.begin()+contador);
			_B_.erase(_B_.begin()+contador);
			_C_.erase(_C_.begin()+contador);
			return;
		}
		contador++;
	}
	cout << endl;
}

void Mostrar(){

	if (_A_.empty()) {
		cout << "Sin grupos ingresados." << endl;
		return;
	}
	//Se declaran todas las variables necesarias
	// A: 0; B: 1; C: 2
	int digitos [4] = {0,0,0,0}, multiplicador_base_diez=1;
	int numero_en_comparacion [3] ,numero_mas_largo [3] = {0,0,0}, numero_de_filas = 0;
	bool tiene_mas_digitos = true;
	bool numero_es_negativo[3] ;


	//En la siguienta parte se intenta conseguir saber un número maximo de digitos
	//(incluyendo el simbolo de menos) que se tenga que presentar en cada columna
	
	//Primero se obtiene el número más largo al convertir en absoluto y luego si el número es
	//negativo se multipluca por diez; y el número mayor es el más largo
	for (auto _b_ : _B_){
		numero_en_comparacion[1]= _b_->get();
		numero_es_negativo[1] = numero_en_comparacion[1] < 0;
		numero_en_comparacion[1]=abs(numero_en_comparacion[1]);
		if(numero_es_negativo[1]){
			numero_en_comparacion[1]*=10;
		}
		if (numero_en_comparacion[1] > numero_mas_largo[1]) {
			numero_mas_largo[1] = abs(_b_->get());
		}

		numero_en_comparacion[0]= _b_->a()->get();
		numero_es_negativo[0] = numero_en_comparacion[0] < 0;
		numero_en_comparacion[0]=abs(numero_en_comparacion[0]);
		if(numero_es_negativo[0]){
			numero_en_comparacion[0]*=10;
		}
		if (numero_en_comparacion[0] > numero_mas_largo[0]) {
			numero_mas_largo[0] = abs(_b_->a()->get());
		}

		numero_en_comparacion[2]= _b_->c()->get();
		numero_es_negativo[2] = numero_en_comparacion[2] < 0;
		numero_en_comparacion[2]=abs(numero_en_comparacion[2]);
		if(numero_es_negativo[2]){
			numero_en_comparacion[2]*=10;
		}
		if (numero_en_comparacion[2] > numero_mas_largo[2]) {
			numero_mas_largo[2] = abs(_b_->c()->get());
		}
		numero_de_filas++;

	}
	//Aquí se cuentan los digitos del número más largo
	for (int clase = 0; clase < 3 ; clase++){
		tiene_mas_digitos=true;
		multiplicador_base_diez = 1;
		while (tiene_mas_digitos){
			digitos[clase]++;
			//cout << digitos[clase] << " , " << clase << endl;
			tiene_mas_digitos =abs(numero_mas_largo[clase]) / multiplicador_base_diez;
			multiplicador_base_diez *= 10;
		}
		if (numero_es_negativo[clase] != true){
			digitos[clase]--;
		}
	}
	//return;
	tiene_mas_digitos=true;
	multiplicador_base_diez=1;
	while (tiene_mas_digitos){
		digitos[3]++;
		tiene_mas_digitos = numero_de_filas / multiplicador_base_diez;
		multiplicador_base_diez *= 10;
	}
	digitos[3]--;

	//Primera linea

	for (int i= 0; i<3 ;i++){ // a los digitos de A,B y C, si son menores de que el número de caracteres utilizados para la presentación de la columna (3) entoces de igualiza las valores de los digitos de A,B y C a este número
		if (digitos[i] <3 ){
			digitos[i] = 3;
		}
	}

	if (digitos[3] < 4) {digitos[3] =4;} //EL número de caracteres utilizados para presentar la columna ID es 4

	cout << " ID ";

	for (int i = 0; i < digitos[3]-4;i++){ //El número de espacios a generar es el números de caracteres a mostrar (el número maximo de digitos a mostrar) menos los caracters por defecto que se deben mostrar en todas las iteraciones
		cout << " ";
	}
	cout << "| A ";

	for (int i = 0; i <digitos[0]-3;i++){
		cout << " ";
	}

	cout << "| B ";

	for (int i = 0; i < digitos[1]-3; i++){
		cout << " ";
	}
	cout << "| C " << endl;
	//Segunda linea
	cout << "----";
	for (int i = 0; i < digitos[3]-4;i++){
		cout << "-";
	}
	cout << "+";
	for (int clase = 0; clase<3;clase++){
		cout << "---";
		for (int i = 0; i < digitos[clase] - 3;i++){
			cout << "-";
		}
		cout << "+";
	}
	cout << endl;

	//Resto de lineas
	

	int ID = 1;

	for (auto _a_ : _A_){
		cout << ID;
		for (int i = 0; i< ( digitos[3] - to_string(ID).size() ) ;i++){
			cout << " ";
		}
		cout << "|" ;
	       	_a_->PrintInt();
		for (int i=0;i< ( digitos[0] - to_string(_a_->get()).size() );i++){
			cout << "+";
		}
		cout << "|";
		_a_->b()->PrintInt();
		for (int i=0; i < ( digitos[1] - to_string(_a_->b()->get()).size() );i++ ){
			cout << "-";
		}
		cout << "|";
		_a_->c()->PrintInt();
		for(int i = 0; i < ( digitos[2] - to_string(_a_->c()->get()).size() ) ; i++){
			cout << "*";
		}
		cout << "|" <<endl;

		ID++;

	}
	cout << endl;
}

void Modificar(){
	int input_generico;
	unsigned int   id;
	cout << "Ingresar la ID del grupo: ";
	cin >> id;

	if (id > _A_.size()) { cout <<  "Error el valor ingresado es demaciado grande" << endl; return; }
	
	id--; // Asi va ha concordar el número de grupo del vector (empieza en 0) con lo presentado al usuario (empieza en 1)
	cout << "¿Desea cambiar el valor de A? (0: si, *: no)";
	cin >> input_generico;
	cout << endl;

	if (input_generico == 0){
		cout << "Ingrese el nuevo valor: ";
		cin >> input_generico;
		_A_.at(id)->set(input_generico);
	}
	cout << "¿Desea cambiar el valor de B? (0: si, *: no)";
	cin >> input_generico;
	cout << endl;

	if (input_generico == 0){
		cout << "Ingrese el nuevo valor: ";
		cin >> input_generico;
		_B_.at(id)->set(input_generico);
	}
	cout << "¿Desea cambiar el valor de C? (0: si, *: no)";
	cin >> input_generico;
	cout << endl;

	if (input_generico == 0){
		cout << "Ingrese el nuevo valor: ";
		cin >> input_generico;
		_C_.at(id)->set(input_generico);
	}
	cout << endl;
}
