#include "DTReservaIndividual.h"

// No es necesario implementar el constructor ya que se utiliza la lista de inicialización en la declaración de la clase

bool DTReservaIndividual::getPagado() const {
    return pagado;
}

void DTReservaIndividual::setPagado(bool pagado) {
    this->pagado = pagado;
}
