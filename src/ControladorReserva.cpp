#include "../include/ControladorReserva.h"
#include "../include/ReservaGrupal.h"
#include "../include/ReservaIndividual.h"
#include "../include/Suscripciones.h"

ControladorReserva* ControladorReserva::instance = NULL;

ControladorReserva::ControladorReserva(){
  this->codigoGenerado = 1;
}

//Getters

ControladorReserva* ControladorReserva::getInstance(){
  if(instance == NULL)
    instance = new ControladorReserva();
  return instance;
}

Reserva* ControladorReserva::getReservaRecordada(){
  return this->reservaRecordada;
}

string ControladorReserva::getNombreRecordado(){
  return this->nombreRecordado;
}

string ControladorReserva::getEmailRecordado(){
  return this->emailRecordado;
}

DTFecha ControladorReserva::getCheckInRecordado(){
  return this->checkInRecordado;
}

DTFecha ControladorReserva::getCheckOutRecordado(){
  return this->checkOutRecordado;
}

int ControladorReserva::getNumeroDeHabitacionRecordado(){
  return this->numeroDeHabitacionRecordado;
}

Estadia* ControladorReserva::getEstadiaRecordada(){
  return this->estadiaRecordada;
}

//Setters
void ControladorReserva::setReservaRecordada(Reserva* reserva){
  this->reservaRecordada = reserva;
}

void ControladorReserva::setNombreRecordado(string nombre){
  this->nombreRecordado = nombre;
}
void ControladorReserva::setEmailRecordado(string email){
  this->emailRecordado = email;
}

void ControladorReserva::setCheckInRecordado(DTFecha checkIn){
  this->checkInRecordado = checkIn;
}

void ControladorReserva::setCheckOutRecordado(DTFecha checkOut){
  this->checkOutRecordado = checkOut;
}

void ControladorReserva::setNumeroDeHabitacionRecordado(int numeroDeHabitacion){
  this->numeroDeHabitacionRecordado = numeroDeHabitacion;
}

void ControladorReserva::setEstadiaRecordada(Estadia* estadiaIngresado){
  this->estadiaRecordada = estadiaIngresado;
}

//Realizar Reserva

void ControladorReserva::confirmarReserva(){
  ControladorUsuario* controladorUsuario = ControladorUsuario::getInstance();
  ControladorHostal* controladorHostal = ControladorHostal::getInstance();
  map<string, Huesped*> huespedes = controladorUsuario->getHuespedesRecordados();
  int cantHuespedes = huespedes.size();
  if (cantHuespedes > 1) {
    ReservaGrupal* nueva = new ReservaGrupal(this->codigoGenerado, controladorHostal->getCheckInRecordado(), controladorHostal->getCheckOutRecordado(), controladorHostal->getHabitacionRecordada(), Abierta, huespedes, controladorHostal->getHostalRecordado());
    this->codigoGenerado++;
  }
  else {
    ReservaIndividual* nueva = new ReservaIndividual(this->codigoGenerado, controladorHostal->getCheckInRecordado(), controladorHostal->getCheckOutRecordado(), controladorHostal->getHabitacionRecordada(), Abierta, huespedes.begin()->second, controladorHostal->getHostalRecordado());
    this->codigoGenerado++;
  }
}

//Registrar Estadia

void ControladorReserva::seleccionarReserva(int codigo) {
  ControladorUsuario* controladorUsuario = ControladorUsuario::getInstance();
  Usuario* usuarioRecordado = controladorUsuario->getUsuarioRecordado();
  Huesped* huesped = dynamic_cast<Huesped*>(usuarioRecordado);
  map<int, Reserva*> :: iterator it;
  map<int, Reserva*> reservas = huesped->getReservas();
  it = reservas.begin();
  while(it != reservas.end() && it->first != codigo){
    it++;
  }
  this->setReservaRecordada(it->second);
}

void ControladorReserva::crearEstadia(){
  Reserva* reserva = this->reservaRecordada;
  ControladorUsuario* controladorUsuario = ControladorUsuario::getInstance();
  HoraDelSistema* horaDelSistema = HoraDelSistema::getInstance();
  Usuario* usuarioRecordado = controladorUsuario->getUsuarioRecordado();
  Huesped* huesped = dynamic_cast<Huesped*>(usuarioRecordado);
  DTFecha fecha = horaDelSistema->getFecha();
  Estadia* nuevaEstadia = new Estadia(fecha, false, huesped, reserva);
  reserva->agregarEstadia(nuevaEstadia);
  huesped->agregarEstadia(nuevaEstadia);
}

//Finalizar Estadia 
void ControladorReserva::seleccionarEstadiaActiva(string email){
  ControladorUsuario* controladorUsuario = ControladorUsuario::getInstance();
  map<string, Huesped*> huespedes = controladorUsuario->getHuespedes();
  map<string, Huesped*>::iterator itHues = huespedes.find(email);
  vector<Estadia*> estadias = itHues->second->getEstadias();
  int i = 0;
  while ( i < estadias.size() && !(estadias[i]->getEstaActiva())) {
    i++;
  }
  try{
    if (i < estadias.size()) {
      this->estadiaRecordada = estadias[i];  
    }
    else {
      this->estadiaRecordada = NULL; 
      throw std::invalid_argument("No hay estadías activas para este huésped.");
    }
  }
  catch(std::invalid_argument &a){
    std::cout<<std::endl <<a.what() << std::endl;
  }
}

void ControladorReserva::finalizarEstadia() {
  Estadia* estadia= this->estadiaRecordada;
  HoraDelSistema* horaDelSis = HoraDelSistema::getInstance();
  DTFecha checkOut = horaDelSis->getFecha();
  estadia->setCheckOut(checkOut);
  estadia->setEstaActiva(false);
}

//Consulta Estadia
bool ControladorReserva::seleccionarEstadia(string emailIngresado, int codigoIngresado){
  ControladorUsuario* controladorUsuario = ControladorUsuario::getInstance();
  Huesped* user = controladorUsuario->getHuesped(emailIngresado);
  vector<Estadia*> estadias = user->getEstadias();
  int i = 0;
  while(i < estadias.size() && estadias[i]->getReserva()->getCodigo() != codigoIngresado)
    i++;
  if (i < estadias.size()){
    this->estadiaRecordada = estadias[i];
    return NULL != estadias[i]->getEvaluacion();
  }
  else
    return false;
}

DTReserva* ControladorReserva::obtenerReservaAsociada(){
  return this->estadiaRecordada->getReserva()->getDatos();
}

DTEvaluacion ControladorReserva::obtenerEvaluacionAsociada(){
  return this->estadiaRecordada->getEvaluacion()->getDatos();
}

void ControladorReserva::ingresarCalificacion(string comentario,int  calificacion) {
  Estadia* estadiaAComentar = this->getEstadiaRecordada();
  ControladorHostal* controladorHostal = ControladorHostal::getInstance();
  //lo de hora del sistema
  Hostal* hostal = controladorHostal->getHostalRecordado();
  HoraDelSistema* interfazHora = HoraDelSistema::getInstance();
  DTFecha fechaActual = interfazHora->getFecha();
  Evaluacion* nueva = new Evaluacion(calificacion, comentario, fechaActual, estadiaAComentar, hostal);
  Suscripciones * suscripcionesSingle = Suscripciones::getInstance();
  suscripcionesSingle->nuevaEvaluacion(nueva);
}

//Baja de Reserva

void ControladorReserva::seleccionarReservaPorHostal(int codigo) {
  ControladorHostal* controladorHostal = ControladorHostal::getInstance();
  Hostal* hostal = controladorHostal->getHostalRecordado();
  map<int, Reserva*> reservas = hostal->getReservas();
  map<int, Reserva*> :: iterator it = reservas.begin();
  while(it != reservas.end() && it->first != codigo)
    it++;
  
  //it = hostal->getReservas().find(codigo);
  this->setReservaRecordada(it->second);
}

void ControladorReserva::confirmarBajadeReserva() {
  Reserva* reserva = this->getReservaRecordada();
  reserva->destruirEstadias();
  reserva->removerReservaDeHuespedes();
  reserva->getHostal()->removerReserva(reserva);
  reserva->getHabitacion()->removerReserva(reserva);
  delete reserva;
}