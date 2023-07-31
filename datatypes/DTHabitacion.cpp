#include "DTHabitacion.h"

DTHabitacion::DTHabitacion(){}//faltaba esto, creo

DTHabitacion::DTHabitacion(int numeroIngresado, int capacidadIngresado, float precioIngresado){
  this->numero = numeroIngresado;
  this->capacidad = numeroIngresado;
  this->precio = precioIngresado;
}

int DTHabitacion::getNumero(){
  return this->numero;
}

int DTHabitacion::getCapacidad(){
  return this->capacidad;
}

float DTHabitacion::getPrecio(){
  return this->precio;
}