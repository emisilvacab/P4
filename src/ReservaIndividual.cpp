#include "../include/ReservaIndividual.h"

ReservaIndividual::ReservaIndividual(int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, Habitacion* habitacionIngresado, EstadoReserva estadoIngresado, Huesped* huespedIngresado, Hostal* hostalIngresado){
  this->setCodigo(codigoIngresado);
  this->setCheckIn(checkInIngresado);
  this->setCheckOut(checkOutIngresado);
  this->setEstado(estadoIngresado);
  this->setHabitacion(habitacionIngresado);
  this->huesped = huespedIngresado;
  this->setHostal(hostalIngresado);
  //Links
  habitacionIngresado->addReserva(this);
  hostalIngresado->addReserva(this); 
  huespedIngresado->addReserva(this);
};

Huesped* ReservaIndividual::getHuesped(){
  return this->huesped;
};

DTReserva* ReservaIndividual::getDatos(){
 DTReservaIndividual* res = new DTReservaIndividual(this->getCodigo(), this->getCheckIn(), this->getCheckOut(), this->getEstado(), this->getCosto(), this->huesped->getDatos(), this->getHabitacion()->getNumero());
 return res;
}

float ReservaIndividual::getCosto(){
  int cantDias = (this->getCheckOut().getAnio() - this->getCheckIn().getAnio() +1)*12*31 - (this->getCheckIn().getMes() + 11 - this->getCheckOut().getMes())*31 - (this->getCheckIn().getDia() + 31 -this->getCheckOut().getDia());
  return this->getHabitacion()->getPrecio() * cantDias;
}

void ReservaIndividual::removerReservaDeHuespedes() {
  this->huesped->removerReserva(this);
}