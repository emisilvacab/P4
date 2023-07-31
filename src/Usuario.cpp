#include "../include/Usuario.h"
#include "../include/Reserva.h"

Usuario::Usuario(){}

Usuario::~Usuario(){}

string Usuario::getNombre(){
  return this->nombre;
}

string Usuario::getEmail(){
  return this->email;
}

string Usuario::getPassword() {
  return this->password;
}

void Usuario::setNombre(string nombreIngresado){
  this->nombre = nombreIngresado;
}

void Usuario::setEmail(string emailIngresado){
  this->email = emailIngresado;
}

void Usuario::setPassword(string passwordIngresado){
  this->password = passwordIngresado;
}
