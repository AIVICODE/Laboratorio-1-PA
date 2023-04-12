#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

B::B(int nuevo_valor){
	this.b=nuevo_valor;
	this.A_link=nullptr;
	this.C_link=nullptr;
}
B::get(){
	return this.b;
}
B::A(){
	return A_link;
}
B::C(){
	return C_link;
}
B::set(int nuevo_valor){
	this.b=nuevo_valor;
}
B::link(A * nuevo_A_link){
	this.A_link = nuevo_A_link;
}
B::link(C * nuevo_C_link){
	this.C_link = nuevo_C_link;
}
B::PrintInt(){
	cout << this.b << endl;
}
