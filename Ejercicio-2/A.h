#ifndef A_H
#define A_H

#include "B.h"
#include "C.h"

class B;
class C;

class A {
	private:
	int a;
	B * B_link;
	C * C_link;
	public:
	A(int nuevo_valor);
	int get();
	B * b();
	C * c();
	void set(int nuevo_valor);
	void link(B * nuevo_B_link);
	void link(C * nuevo_C_link);
	void PrintInt();

};

#endif
