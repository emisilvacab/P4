#include "../include/Reserva.h"
#include "../include/Habitacion.h"
#include "../include/Estadia.h"


Reserva::Reserva(){}

Reserva::~Reserva(){}

int Reserva::getCodigo(){
  return this->codigo;
}

DTFecha Reserva::getCheckIn(){
  return this->checkIn;
}

DTFecha Reserva::getCheckOut(){
  return this->checkOut;
}

EstadoReserva Reserva::getEstado(){
  return this->estado;
}

Habitacion* Reserva::getHabitacion(){
  return this->habitacion;
}

vector<Estadia*> Reserva::getEstadias(){
  return this->estadias;
}

vector<Estadia*> Reserva::getEstadiasFinalizadas(){
  vector<Estadia*> res;
  vector<Estadia*> estadias = this->estadias;
  for (Estadia* est : estadias){
    if (!est->getEstaActiva())
      res.push_back(est);
  }
  return res;
  
}

Hostal* Reserva::getHostal() {
  return this->hostal;
}

void Reserva::setCodigo(int codigoIngresado){
  this->codigo = codigoIngresado;
}

void Reserva::setCheckIn(DTFecha checkInIngresado){
  this->checkIn = checkInIngresado;
}

void Reserva::setCheckOut(DTFecha checkOutIngresado){
  this->checkOut = checkOutIngresado;
}

void Reserva::setEstado(EstadoReserva estadoIngresado){
  this->estado = estadoIngresado;
}

void Reserva::setHabitacion(Habitacion* habitacionIngresada){
  this->habitacion = habitacionIngresada;
}

void Reserva::setHostal(Hostal* hostal) {
  this->hostal = hostal;
}

void Reserva::agregarEstadia(Estadia* estadia){
  this->estadias.push_back(estadia);
}

void Reserva::destruirEstadias(){
  for(int i=0; i < this->estadias.size(); i++) {
    if (this->estadias[i]->getEvaluacion() != NULL)
      this->estadias[i]->destruirEvaluaciones();
    this->estadias[i]->getHuesped()->removerEstadia(this->estadias[i]); //no ocurre nada si el huésped no tiene estadías
    //si hubiera consumos se removeria la estadia de ahi también 
    delete this->estadias[i];
  }
}


