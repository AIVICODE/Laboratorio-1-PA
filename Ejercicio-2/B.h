#ifndef B_H
#define B_H

#include "A.h"
#include "C.h"

class B {
	private:
	int b;
	A * A_link;
	C * C_link;
	public:
	B(int nuevo_valor);
	int get();
	void set(int nuevo_valor);
	A * A();
	C * C();
	void link(A * nuevo_A_link);
	void link(C * nuevo_C_link);
	void PrintInt();

}

#endif
