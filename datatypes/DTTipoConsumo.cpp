#include "DTTipoConsumo.h"

DTTipoConsumo::DTTipoConsumo(string nombreIngresado, string codigoIngresado, float precioIngresado){
  this->nombre = nombreIngresado;
  this->codigo = codigoIngresado;
  this->precio = precioIngresado;
}

string DTTipoConsumo::getNombre(){
  return this->nombre;
}

string DTTipoConsumo::getCodigo(){
  return this->codigo;
}

float DTTipoConsumo::getPrecio(){
  return this->precio;
}
