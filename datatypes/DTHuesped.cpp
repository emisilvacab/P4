#include "DTHuesped.h"

DTHuesped::DTHuesped(){}

DTHuesped::DTHuesped(string nombreIngresado, string emailIngresado, string passwordIngresado, bool esFingerIngresado){
  this->setNombre(nombreIngresado);
  this->setEmail(emailIngresado);
  this->setPassword(passwordIngresado);
  this->setEsFinger(esFingerIngresado);
}

bool DTHuesped::getEsFinger(){
  return this->esFinger;
}

void DTHuesped::setEsFinger(bool esFingerIngresado){
  this->esFinger = esFingerIngresado;
}

void DTHuesped::printUsuario(ostream &o){
  o<<"El usuario es un Huesped"<< "\n";
  o<<"Nombre: "<<this->getNombre() <<"\n";
  o<<"Email: "<<this->getEmail()<<"\n";
  if (this->getEsFinger())
    o<<"Es finger \n";
  else
    o<<"No es finger \n";

}