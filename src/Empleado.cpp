#include "../include/Empleado.h"
#include "../include/Hostal.h"
#include "../include/Notificacion.h"

Empleado::Empleado(){}

Empleado::Empleado(string nombreIngresado, string emailIngresado, string passwordIngresado, TipoCargo cargoIngresado){
  this->hostal = NULL;
  this->setNombre(nombreIngresado);
  this->setEmail(emailIngresado);
  this->setPassword(passwordIngresado);
  this->cargo = cargoIngresado;
}

Empleado::~Empleado() {}

Hostal* Empleado::getHostal(){
  return this->hostal;
}

TipoCargo Empleado::getCargo(){
  return this->cargo;
}

vector<Notificacion*> Empleado::getNotificaciones() {
  return this->notificaciones;
}

void Empleado::setCargo(TipoCargo cargoIngresado){
  this->cargo = cargoIngresado;
}

void Empleado::setHostal(Hostal* hostalIngresado){
  this->hostal = hostalIngresado;
}

bool Empleado::empleadoNoAsignado(){
  return this->hostal==NULL;
}

void Empleado::linkHostal(Hostal* hostalIngresado, TipoCargo cargoIngresado){
  this->hostal = hostalIngresado;
  this->cargo = cargoIngresado;
}

void Empleado::addEvaluacion(Evaluacion* evaluacion){
  this->evaluaciones.push_back(evaluacion);
}

void Empleado::removerEvaluacion(Evaluacion* evaluacion) {
  vector<Evaluacion*>::iterator it = this->evaluaciones.begin();
  while (it != this->evaluaciones.end() && *it != evaluacion)
    it++;
  if (it != this->evaluaciones.end())
    this->evaluaciones.erase(it);
}

void Empleado::notificar(Notificacion * notificacionIngresada) {
  this->notificaciones.push_back(notificacionIngresada);
}

void Empleado::limpiarNotificaciones(){
  this->notificaciones.clear();
}