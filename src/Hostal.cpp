#include "../include/Hostal.h"
#include "../include/Habitacion.h"
#include "../include/Evaluacion.h"
#include "../include/Reserva.h"

using std::string;

Hostal::Hostal(string nombreIngresado, string direccionIngresado, string telefonoIngresado){
  this->nombre = nombreIngresado;
  this->direccion = direccionIngresado;
  this->telefono = telefonoIngresado;
  map<int,Habitacion*> habitacionesVacio;
  this->habitaciones = habitacionesVacio;
  vector<Evaluacion*> ev;//inicializar el vector de evaluaciones
  this->evaluaciones = ev;
}//no tiene como parametro de entrada el map

string Hostal::getNombre(){
  return this->nombre;
}

string Hostal::getDireccion(){
  return this->direccion;
}

string Hostal::getTelefono(){
  return this->telefono;
}

map<int, Habitacion*> Hostal::getHabitaciones(){
  return this->habitaciones;
}

map<int, Reserva*> Hostal::getReservas(){
  return this->reservas;
}
    
vector<Evaluacion*> Hostal::getEvaluaciones(){
  return this->evaluaciones;
}

map<string, Empleado*> Hostal::getEmpleados(){
  return this->empleados;
}


vector<DTEvaluacion> Hostal::getDTEvaluaciones(){
  vector<Evaluacion*> evaluaciones = this->evaluaciones;
  vector<DTEvaluacion> res;
  for(int i = 0; i < evaluaciones.size(); i++){
      res.push_back(evaluaciones[i]->getDatos());
  }
  return res;
}


float Hostal::getPromedio(){
  float resultado = 0;
  vector<Evaluacion*> evaluaciones = this->evaluaciones;
  for(int i=0; i<evaluaciones.size(); i++){
    resultado += evaluaciones[i]->getCalificacion();
  }
  if ( evaluaciones.size() > 1)
    resultado /= evaluaciones.size();
  return resultado;
}

void Hostal::setNombre(string nombreIngresado){
  this->nombre = nombreIngresado;
}

void Hostal::setDireccion(string direccionIngresado){
  this->direccion = direccionIngresado;
}

void Hostal::setTelefono(string telefonoIngresado){
  this->telefono = telefonoIngresado;
}

void Hostal::addReserva(Reserva* reservaIngresado) {
  this->reservas.insert({reservaIngresado->getCodigo(), reservaIngresado});
}

void Hostal::addEmpleado(Empleado* empleadoIngresado){
  this->empleados.insert({empleadoIngresado->getEmail(), empleadoIngresado});
}

void Hostal::addHabitacion(Habitacion* habitacion){
  this->habitaciones.insert({habitacion->getNumero(), habitacion});
}

void Hostal::addEvaluacion(Evaluacion* evaluacionIngresado) {
  this->evaluaciones.push_back(evaluacionIngresado);
}

Habitacion* Hostal::getHabitacion(int num){
  map<int,Habitacion*> habitaciones = this->getHabitaciones();
  map<int,Habitacion*>::iterator it = habitaciones.begin();
  while(it!=habitaciones.end() && it->second->getNumero()!= num){
    it++;
  }
  Habitacion* hab = it->second;
  return hab;
}

vector<DTReserva*> Hostal::getDatosReservas() {
  vector<DTReserva*> res;
  map<int, Reserva*>::iterator it;
  for(it = this->reservas.begin(); it != this->reservas.end(); it++) {
    res.push_back(it->second->getDatos());
  }
  return res;
}

DTHostal Hostal::getDatos(){
  return DTHostal(this->nombre, this->direccion, this->telefono);
}

void Hostal::removerEvaluacion(Evaluacion* evaluacion) {
  vector<Evaluacion*>::iterator it = this->evaluaciones.begin();
  while (it != this->evaluaciones.end() && *it != evaluacion)
    it++;
  if (it != this->evaluaciones.end())
    this->evaluaciones.erase(it);
}

void Hostal::removerReserva(Reserva* reserva) {
  this->reservas.erase(reserva->getCodigo());
}