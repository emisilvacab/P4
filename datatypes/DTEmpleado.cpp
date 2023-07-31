#include "DTEmpleado.h"

DTEmpleado::DTEmpleado(){}

DTEmpleado::DTEmpleado(string nombreIngresado, string emailIngresado, string passwordIngresado, TipoCargo cargoIngresado){
  this->setNombre(nombreIngresado);
  this->setEmail(emailIngresado);
  this->setPassword(passwordIngresado);
  this->cargo = cargoIngresado;
  this->hostal = "";
};

TipoCargo DTEmpleado::getCargo(){
  return this->cargo;
};

void DTEmpleado::setTipoCargo(TipoCargo tipoCargoIngresado){
  this->cargo = tipoCargoIngresado;
};

void DTEmpleado::setHostal(string hostalIngresado){
  this->hostal = hostalIngresado;
};

string DTEmpleado::getHostal(){
  return this->hostal;
};

void DTEmpleado::printUsuario(ostream &o){
  o<<"El usuario es un Empleado"<< "\n";
  o<<"Nombre: "<<this->getNombre() <<"\n";
  o<<"Email: "<<this->getEmail()<<"\n";
  if (this->getHostal() == "")
      o<<"No tiene ningún hostal asignado, pero su cargo es "<<cargoAString(this->getCargo())<<"\n";
  else
      o<<"Trabaja en el hostal "<<this->getHostal()<<", con el cargo de "<<cargoAString(this->getCargo())<<"\n";
}
