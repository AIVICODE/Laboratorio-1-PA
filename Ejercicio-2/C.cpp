#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"
using namespace std;

C::C(int nuevo_valor){
	this->c=nuevo_valor;
	this->A_link=nullptr;
	this->B_link=nullptr;
}
int C::get(){
	return this->c;
}
A * C::a(){
	return A_link;
}
B * C::b(){
	return B_link;
}
void C::set(int nuevo_valor){
	this->c=nuevo_valor;
}
void C::link(A * nuevo_A_link){
	this->A_link = nuevo_A_link;
}
void C::link(B * nuevo_B_link){
	this->B_link = nuevo_B_link;
}
void C::PrintInt(){
	cout << this->c;
}
