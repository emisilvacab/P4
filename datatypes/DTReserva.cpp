#include "DTReserva.h"

DTReserva::DTReserva(){}
DTReserva::~DTReserva(){}


int DTReserva::getCodigo(){
  return this->codigo;
}

DTFecha DTReserva::getCheckIn(){
  return this->checkIn;
}

DTFecha DTReserva::getCheckOut(){
  return this->checkOut;
}

EstadoReserva DTReserva::getEstado(){
  return this->estado;
}

float DTReserva::getCosto(){
 return this->costo;
}

int DTReserva::getNumHabitacion() {
  return this->numHabitacion;
}


void DTReserva::setCodigo(int codigoIngresado){
  this->codigo = codigoIngresado;
}

void DTReserva::setCheckIn(DTFecha checkInIngresado){
  this->checkIn = checkInIngresado;
}

void DTReserva::setCheckOut(DTFecha checkOutIngresado){
  this->checkOut = checkOutIngresado;
}

void DTReserva::setEstado(EstadoReserva estadoIngresado){
  this->estado = estadoIngresado;
}

void DTReserva::setCosto(float costoIngresado){
  this->costo = costoIngresado;
}

void DTReserva::setNumHabitacion(int numHabitacionIngresado) {
  this->numHabitacion = numHabitacionIngresado;
}

ostream &operator << (ostream &output, DTReserva &reserva){
  reserva.printReserva(output);
  return output;
}