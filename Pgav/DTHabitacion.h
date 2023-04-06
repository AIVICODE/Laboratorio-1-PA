#ifndef DTHabitacion_H
#define DTHabitacion_
class DTHabitacion{
	private:
		int numero;
		float precio;
		int capacidad;
	public:
		DTHabitacion(int _numero, float _precio, int _capacidad);
		void SetNumero(int nuevo_numero);
		void SetPrecio(float nuevo_precio);
		void SetCapacidad(int nueva_capacidad);
		int GetNumero();
		float GetPrecio();
		int GetCapacidad();
};
#endif
