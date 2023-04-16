#ifndef C_H
#define C_H

#include "A.h"
#include "B.h"

class A;
class B;

class C {
	private:
	int c;
	A * A_link;
	B * B_link;
	public:
	C(int nuevo_valor);
	int get();
	void set(int nuevo_valor);
	A * a();
	B * b();
	void link(A * nuevo_A_link);
	void link(B * nuevo_C_link);
	void PrintInt();

};

#endif
