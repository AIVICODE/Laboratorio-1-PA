#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

C::C(int nuevo_valor){
	this.c=nuevo_valor;
	this.A_link=nullptr;
	this.B_link=nullptr;
}
C::get(){
	return this.c;
}
C::A(){
	return A_link;
}
C::B(){
	return B_link;
}
C::set(int nuevo_valor){
	this.c=nuevo_valor;
}
C::link(A * nuevo_A_link){
	this.A_link = nuevo_A_link;
}
C::link(B * nuevo_B_link){
	this.B_link = nuevo_B_link;
}
C::PrintInt(){
	cout << this.c << endl;
}
