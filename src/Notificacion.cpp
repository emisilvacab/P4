#include "../include/Notificacion.h"

Notificacion::Notificacion(Evaluacion* evaluacionIngresado){
  this->evaluacion = evaluacionIngresado;
}

int Notificacion::getCantNotificados() {
  return this->cantNotificados;
}

Evaluacion* Notificacion::getEvaluacion() {
  return this->evaluacion;
}

void Notificacion::setCantNotificados(int cantIngresado) {
  this->cantNotificados = cantIngresado;
}

void Notificacion::setEvaluacion(Evaluacion* evaluacionIngresado){
  this->evaluacion = evaluacionIngresado; 
}