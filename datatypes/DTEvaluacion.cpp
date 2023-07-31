#include "DTEvaluacion.h"

using std::endl;

void DTEvaluacion::printEvaluacion(ostream &o){
  o << "Calificacion: " << this->calificacion << endl;
  o << "Comentario: " << this->comentario << endl;
  o << "Fecha: " << this->fecha.getHora() << " hs " << this->fecha.getDia() << "/" << this->fecha.getMes() << "/" << this->fecha.getAnio()<<endl;
  if (this->respuesta != "")
    o << "Respuesta: " << this->respuesta<<endl;
}

DTEvaluacion::DTEvaluacion(int calificacionIngresado, string comentarioIngresado, string respuestaIngresado, DTFecha fechaIngresado){
  this->calificacion = calificacionIngresado;
  this->comentario = comentarioIngresado;
  this->respuesta = respuestaIngresado;
  this->fecha = fechaIngresado;
}

int DTEvaluacion::getCalificacion(){
  return this->calificacion;
}

string DTEvaluacion::getComentario(){
  return this->comentario;
}

string DTEvaluacion::getRespuesta(){
  return this->respuesta;
}

DTFecha DTEvaluacion::getFecha(){
  return this->fecha;
}

string DTEvaluacion::getMailAutor() {
  return this->mailAutor;
}
void DTEvaluacion::setMailAutor(string mailAutorIngresado) {
  this->mailAutor = mailAutorIngresado;
}

ostream &operator << (ostream &output, DTEvaluacion &evaluacion){
  evaluacion.printEvaluacion(output);
  return output;
}