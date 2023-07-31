#include "DTUsuario.h"

//DTUsuario::DTUsuario() {};

DTUsuario::~DTUsuario() {}

string DTUsuario::getNombre(){
  return this->nombre;
}

string DTUsuario::getEmail(){
  return this->email;
}
string DTUsuario::getPassword(){
  return this->password;
}

void DTUsuario::setNombre(string nombreIngresado){
  this->nombre = nombreIngresado;
} 

void DTUsuario::setEmail(string emailIngresado){
  this->email = emailIngresado;
}
void DTUsuario::setPassword(string passwordIngresado){
  this->password = passwordIngresado;
}

ostream &operator <<(ostream &output, DTUsuario &usuario){
  usuario.printUsuario(output);
  return output;

}