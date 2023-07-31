#include "DTHostalCalificacion.h"

using std::endl;

DTHostalCalificacion::DTHostalCalificacion(){}//faltaba esto, creo

DTHostalCalificacion::DTHostalCalificacion(string nombreIngresado, string direccionIngresado, string telefonoIngresado, float calificacionPromedioIngresado){
  this->nombre = nombreIngresado;
  this->direccion = direccionIngresado;
  this->telefono = telefonoIngresado;
  this->calificacionPromedio = calificacionPromedioIngresado;
}

string DTHostalCalificacion::getNombre(){
  return this->nombre;
}

string DTHostalCalificacion::getDireccion(){
  return this->direccion;
}

string DTHostalCalificacion::getTelefono(){
  return this->telefono;
}

float DTHostalCalificacion::getCalificacionPromedio(){
  return this->calificacionPromedio;
}

ostream &operator << (ostream &output, DTHostalCalificacion &hostal){
  output << "Nombre: " << hostal.getNombre() << endl;
  output << "Direccion: " << hostal.getDireccion() << endl;
  output << "Teléfono: " << hostal.getTelefono() << endl;
  output << "Calificación: " << hostal.getCalificacionPromedio() << endl;
  return output;
}