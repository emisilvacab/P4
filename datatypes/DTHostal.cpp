#include "DTHostal.h"

using std::ostream;
using std::endl;

DTHostal::DTHostal(){}//faltaba esto, creo

DTHostal::DTHostal(string nombreIngresado, string direccionIngresado, string telefonoIngresado){
  this->nombre = nombreIngresado;
  this->direccion = direccionIngresado;
  this->telefono = telefonoIngresado;
}

string DTHostal::getNombre(){
  return this->nombre;
}

string DTHostal::getDireccion(){
  return this->direccion;
}

string DTHostal::getTelefono(){
  return this->telefono;
}

ostream &operator << (ostream &output, DTHostal &hostal){
  output<<hostal.getNombre()<<endl;
  return output;
}