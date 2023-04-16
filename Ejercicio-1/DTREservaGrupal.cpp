#include "DTREservaGrupal.h"

// No es necesario implementar el constructor ya que se utiliza la lista de inicialización en la declaración de la clase

const std::vector<DTHuesped>& DTReservaGrupal::getHuespedes() const {
    return huespedes;
}

void DTReservaGrupal::setHuespedes(const std::vector<DTHuesped>& huespedes) {
    this->huespedes = huespedes;
}

int DTReservaGrupal::getCantHuespedes() const {
    return huespedes.size();
}