#include "../include/Habitacion.h"
#include "../include/Reserva.h"

Habitacion::Habitacion(int numeroIngresado, int capacidadIngresado, float precioIngresado, Hostal* hostalIngresado){
  this->numero = numeroIngresado;
  this->capacidad = capacidadIngresado;
  this->precio = precioIngresado;
  this->hostal = hostalIngresado;
  hostalIngresado->addHabitacion(this);
}

int Habitacion::getNumero(){
  return this->numero;
}

int Habitacion::getCapacidad(){
  return this->capacidad;
}

float Habitacion::getPrecio(){
  return this->precio;
}

Hostal* Habitacion::getHostal() {
  return this->hostal;
}

map<string, TipoConsumo*> Habitacion::getTipoConsumos() {
  return this->tipoConsumos;
}

map<int, Reserva*> Habitacion::getReservas() {
  return this->reservas;
}

void Habitacion::setNumero(int numeroIngresado){
  this->numero = numeroIngresado;
}

void Habitacion::setCapacidad(int capacidadIngresado){
  this->capacidad = capacidadIngresado;
}

void Habitacion::setPrecio(float precioIngresado){
  this->precio = precioIngresado;
}

void Habitacion::addReserva(Reserva* reservaIngresado) {
  this->reservas.insert({reservaIngresado->getCodigo(), reservaIngresado});
}

bool Habitacion::isDisponible(DTFecha checkIn, DTFecha checkOut){
  map<int,Reserva*> reservas = this->getReservas();
  map<int,Reserva*>::iterator it = reservas.begin();

  
  while(it != reservas.end() && (it->second->getCheckIn() < checkIn && it->second->getCheckOut() < checkOut)){
    it++;
  }
  

  /*
  while(it != reservas.end() && !(  (it->second->getCheckIn() < checkIn && checkIn < it->second->getCheckOut())   ||  (it->second->getCheckIn() < checkOut && checkOut < it->second->getCheckOut()) || (checkIn < it->second->getCheckIn() && it->second->getCheckOut()< checkOut )  )){
    it++;
  }
  */
 
  if(it!=reservas.end()){
    return false;
  }else{
    return true;
  }
}

void Habitacion::removerReserva(Reserva* reserva) {
  this->reservas.erase(reserva->getCodigo());
}