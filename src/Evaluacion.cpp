#include "../include/Evaluacion.h"
#include "../include/Hostal.h"


Evaluacion::Evaluacion(int calificacionIngresado, string comentarioIngresado, DTFecha fechaIngresado, Estadia* estadiaIngresado, Hostal* hostalIngresado){
  this->calificacion = calificacionIngresado;
  this->comentario = comentarioIngresado;
  this->respuesta = "";
  this->fecha = fechaIngresado;
  this->estadia = estadiaIngresado;
  this->hostal = hostalIngresado;
  this->empleado = NULL;
  hostalIngresado->addEvaluacion(this);
  estadiaIngresado->setEvaluacion(this);
}

int Evaluacion::getCalificacion(){
  return this->calificacion;
}

string Evaluacion::getComentario(){
  return this->comentario;
}

string Evaluacion::getRespuesta(){
  return this->respuesta;
}

DTFecha Evaluacion::getFecha(){
  return this->fecha;
}

Estadia* Evaluacion::getEstadia(){
  return this->estadia;
}

Hostal* Evaluacion::getHostal(){
  return this->hostal;
}

Empleado* Evaluacion::getEmpleado() {
  return this->empleado;
}

DTEvaluacion Evaluacion::getDatos(){
  DTEvaluacion ans = DTEvaluacion(this->calificacion, this->comentario, this->respuesta, this->fecha);
  ans.setMailAutor(this->estadia->getHuesped()->getEmail()); //se agrego este atributo para el Consulta de Notificaciones
  return ans;
}

Notificacion* Evaluacion::getNotificacion() {
  return this->notificacion;
}

bool Evaluacion::isCalificada(){
  return this->respuesta != "";
}

void Evaluacion::setRespuesta(string respuestaIngresada){
  this->respuesta = respuestaIngresada;
}

void Evaluacion::setEmpleado(Empleado* empleado){
  this->empleado = empleado;
  empleado->addEvaluacion(this);
}

void Evaluacion::setNotificacion(Notificacion* notificacionIngresado) {
  this->notificacion = notificacionIngresado;
}
