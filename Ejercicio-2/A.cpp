#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

A::A(int nuevo_valor){
	this.a=nuevo_valor;
	this.B_link=nullptr;
	this.C_link=nullptr;
}
A::get(){
	return this.a;
}
A::B(){
	return B_link;
}
A::C(){
	return C_link;
}
A::set(int nuevo_valor){
	this.a=nuevo_valor;
}
A::link(B * nuevo_B_link){
	this.B_link = nuevo_B_link;
}
A::link(C * nuevo_C_link){
	this.C_link = nuevo_C_link;
}
A::PrintInt(){
	cout << this.a << endl;
}
