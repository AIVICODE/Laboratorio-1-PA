#include <string.h>
class DTHuesped {
	private:
		string nombre;
		string email;
		bool esFinger;
	public:
		DTHusped(string _nombre, string _email, bool _esFinger);
		void SetEmail(string nuevo_email);
		void SetNombre(string nuevo_nombre);
		void SetEsFinger(bool nuevo_esfinger);
		string GetNombre();
		string GetEmail();
		bool GetEsFinger();
};
