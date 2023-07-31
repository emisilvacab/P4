#include "../include/TipoConsumo.h"

TipoConsumo::TipoConsumo(string codigoIngresado, string nombreIngresado, float precioIngresado){
  this->codigo = codigoIngresado;
  this->nombre = nombreIngresado;
  this->precio = precioIngresado;
}

string TipoConsumo::getCodigo(){
  return this->codigo;
}

string TipoConsumo::getNombre(){
  return this->nombre;
}

float TipoConsumo::getPrecio(){
  return this->precio;
}

void TipoConsumo::setCodigo(string codigoIngresado){
  this->codigo = codigoIngresado;
}

void TipoConsumo::setNombre(string nombreIngresado){
  this->nombre = nombreIngresado;
}

void TipoConsumo::setPrecio(float precioIngresado){
  this->precio = precioIngresado;
}