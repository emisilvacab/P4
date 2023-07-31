#include "DTHabitacionEvaluacion.h"

using std::vector;
using std::endl;

DTHabitacionEvaluacion::DTHabitacionEvaluacion(int numeroIngresado, int capacidadIngresado, float precioIngresado, vector<DTEvaluacion> evaluacionesIngresado){
  this->numero = numeroIngresado;
  this->capacidad = capacidadIngresado;
  this->precio = precioIngresado;
  this->evaluaciones = evaluacionesIngresado;
}

int DTHabitacionEvaluacion::getNumero(){
  return this->numero;
}

int DTHabitacionEvaluacion::getCapacidad(){
  return this->capacidad;
}

float DTHabitacionEvaluacion::getPrecio(){
  return this->precio;
}

vector<DTEvaluacion> DTHabitacionEvaluacion::getEvaluaciones(){
  return this->evaluaciones;
}

ostream &operator << (ostream &output, DTHabitacionEvaluacion &habitacion){
  output << "Numero: " << habitacion.getNumero() << endl;
  output << "Capacidad: " << habitacion.getCapacidad() << endl;
  output << "Precio: " << habitacion.getPrecio() << endl;
  output << "Evaluaciones: " << endl;
  
  vector<DTEvaluacion> evaluaciones = habitacion.getEvaluaciones();
  for(DTEvaluacion ev : evaluaciones){
    output << ev;
  }
  
  return output;
}  