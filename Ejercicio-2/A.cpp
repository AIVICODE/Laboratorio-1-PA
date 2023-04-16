#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;

A::A(int nuevo_valor){
	this->a=nuevo_valor;
	this->B_link=nullptr;
	this->C_link=nullptr;
}
int A::get(){
	return this->a;
}
B * A::b(){
	return B_link;
}
C * A::c(){
	return C_link;
}
void A::set(int nuevo_valor){
	this->a=nuevo_valor;
}
void A::link(B * nuevo_B_link){
	this->B_link = nuevo_B_link;
}
void A::link(C * nuevo_C_link){
	this->C_link = nuevo_C_link;
}
void A::PrintInt(){
	cout << this->a;
}
