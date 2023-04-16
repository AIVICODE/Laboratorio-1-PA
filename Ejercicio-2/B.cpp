#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"
using namespace std;

B::B(int nuevo_valor){
	this->b=nuevo_valor;
	this->A_link=nullptr;
	this->C_link=nullptr;
}
int B::get(){
	return this->b;
}
A * B::a(){
	return A_link;
}
C * B::c(){
	return C_link;
}
void B::set(int nuevo_valor){
	this->b=nuevo_valor;
}
void B::link(A * nuevo_A_link){
	this->A_link = nuevo_A_link;
}
void B::link(C * nuevo_C_link){
	this->C_link = nuevo_C_link;
}
void B::PrintInt(){
	cout << this->b;
}
