#include "../include/Estadia.h"
#include "../include/Evaluacion.h"

Estadia::Estadia(DTFecha checkInIngresado, bool promoIngresado, Huesped* huespedIngresado, Reserva* reservaIngresado){
  this->checkIn = checkInIngresado;
  this->checkOut = DTFecha();
  this->promo = promoIngresado;
  this->totalConsumido = 0;
  this->huesped = huespedIngresado;
  this->reserva = reservaIngresado;
  this->estaActiva = true;
  this->evaluacion = NULL;
}

DTFecha Estadia::getCheckIn() {
  return this->checkIn;
}

DTFecha Estadia::getCheckOut() {
  return this->checkOut;
}

bool Estadia::getPromo() {
  return this->promo;
}

float Estadia::getTotalConsumido() {
  return this->totalConsumido;
}

Evaluacion* Estadia::getEvaluacion(){
  return this->evaluacion;
}

vector<Consumo*> Estadia::getConsumos(){
  return this->consumos;
}

DTEstadia Estadia::getDatos(){
  return DTEstadia(this->huesped->getEmail(), this->reserva->getCodigo(), this->checkIn, this->checkOut, this->promo, this->getTotalConsumido());
}

Reserva* Estadia::getReserva(){
  return this->reserva;
}

bool Estadia::getEstaActiva() {
  return this->estaActiva;
}

Huesped* Estadia::getHuesped(){
  return this->huesped;
}

void Estadia::setHuesped(Huesped* huespedIngresado){
  this->huesped = huespedIngresado;
}

void Estadia::setReserva(Reserva* reservaIngresado){
  this->reserva = reservaIngresado;
}

void Estadia::setCheckIn(DTFecha checkInIngresado) {
  this->checkIn = checkInIngresado;
}

void Estadia::setCheckOut(DTFecha checkOutIngresado) {
  this->checkOut = checkOutIngresado;
}

void Estadia::setPromo(bool promoIngresado) {
  this->promo = promoIngresado;
}

void Estadia::setTotalConsumido(float totalConsumidoIngresado) {
  this->totalConsumido = totalConsumidoIngresado;
}

void Estadia::setEvaluacion(Evaluacion* evaluacionIngresado){
  this->evaluacion = evaluacionIngresado;
}

void Estadia::setEstaActiva(bool activa) {
  this->estaActiva = activa;
}

void Estadia::destruirEvaluaciones() {
  this->evaluacion->getHostal()->removerEvaluacion(this->evaluacion);
  if (this->evaluacion->getEmpleado() != NULL) 
    this->evaluacion->getEmpleado()->removerEvaluacion(this->evaluacion);
  this->evaluacion->getNotificacion()->setEvaluacion(NULL); // se supone que siempre que hay evaluacion hay notificacion //importante para cuando se consulten las notificaciones
  delete this->evaluacion;
  this->evaluacion = NULL; 
}