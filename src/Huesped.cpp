#include "../include/Huesped.h"
#include "../include/Estadia.h"

Huesped::Huesped(string nombreIngresado, string emailIngresado, string passwordIngresado, bool esFingerIngresado) {
  this->setNombre(nombreIngresado);
  this->setEmail(emailIngresado);
  this->setPassword(passwordIngresado);
  this->esFinger = esFingerIngresado;
  vector<Estadia*> estadiasVacio;
  this->estadias = estadiasVacio;
}

bool Huesped::getEsFinger(){
  return this->esFinger;
}

void Huesped::setEsFinger(bool esFinger){
  this->esFinger = esFinger;
}

map<int,Reserva*> Huesped::getReservas(){
  return this->reservas;
}

void Huesped::setReservas(map<int,Reserva*> reservasIngresado){
  this->reservas = reservasIngresado;
}

list<DTReserva*> Huesped::obtenerReservasNoCanceladas() {
  list<DTReserva*> res;
  for(map<int,Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++) {
    if (it->second->getEstado() != Cancelada) {
      DTReserva* aux = it->second->getDatos();
      res.push_front(aux);
    }
  }
  return res;
}

DTHuesped Huesped::getDatos() {
  DTHuesped ans = DTHuesped(this->getNombre(), this->getEmail(), this->getPassword(), this->getEsFinger());
  return ans;
}

void Huesped::agregarEstadia(Estadia* estadia){
  this->estadias.push_back(estadia);
}

void Huesped::addReserva(Reserva* reservaIngresado){
  this->reservas.insert({reservaIngresado->getCodigo(), reservaIngresado});
}

vector<Estadia*> Huesped::getEstadias(){
  return this->estadias;
}

void Huesped::removerEstadia(Estadia* estadia) {
  vector<Estadia*>::iterator it = this->estadias.begin();
  while (it != this->estadias.end() && *it != estadia)
    it++;
  if (it != this->estadias.end())
    this->estadias.erase(it);
}

void Huesped::removerReserva(Reserva* reserva) {
  this->reservas.erase(reserva->getCodigo());
  /*map<int,Reserva*>::iterator it = this->reservas.begin();
  while (it != this->reservas.end() and it->second != reserva)
    it++;
  if (it != this->reservas.end())
    this->reservas.erase(it);*/
}

