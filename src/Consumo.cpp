#include "../include/Consumo.h"

Consumo::Consumo(TipoConsumo* tipoConsumoIngresado){
  this->cantidad = 1;
  this->tipoConsumo = tipoConsumoIngresado;
}

int Consumo::getCantidad(){
  return this->cantidad;
}

TipoConsumo* Consumo::getTipoConsumo(){
  return this->tipoConsumo;
}

void Consumo::setCantidad(int cantidadIngresada){
  this->cantidad = cantidadIngresada;
}