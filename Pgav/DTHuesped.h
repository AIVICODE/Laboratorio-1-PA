#include <string.h>
class DTHuesped {
	private:
		string nombre;
		string email;
		bool esFinger;
	public:
		DTHusped(string _nombre, string _email, bool _esFinger);
		SetEmail(string nuevo_email);
		SetNombre(string nuevo_nombre);
		SetEsFinger(bool nuevo_esfinger);
		GetNombre();
		GetEmail();
		GetEsFinger();
};
