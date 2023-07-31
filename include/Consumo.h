#ifndef Consumo_h
#define Consumo_h

#include "TipoConsumo.h"

class Consumo{
  private:
    int cantidad;
    TipoConsumo* tipoConsumo;
  public:
    Consumo(TipoConsumo* tipoConsumoIngresado/*, int cantidad si es util*/);
    int getCantidad();
    TipoConsumo* getTipoConsumo();
    void setCantidad(int cantidadIngresada);
};

#endif