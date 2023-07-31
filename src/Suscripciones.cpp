#include "../include/Suscripciones.h"
#include "../include/IObserver.h"

Suscripciones* Suscripciones::suscripciones = NULL;

Suscripciones::Suscripciones(){
  vector<IObserver*> vecInicializada;
  this->suscriptos = vecInicializada;
}

Suscripciones* Suscripciones::getInstance() {
  if(suscripciones == NULL)
    suscripciones = new Suscripciones();
  return suscripciones;
}

vector<IObserver*> Suscripciones::getSuscriptos() {
  return this->suscriptos;
}

void Suscripciones::suscribir(IObserver* suscriptor){
  //ControladorUsuario* controladorUsuario = ControladorUsuario::getInstance();
  //Empleado* empleado = controladorUsuario->getEmpleado(suscriptor.getEmail());
  //this->suscriptos.insert({suscriptor.getEmail(), empleado});
  //suscriptos es un map<string,IObserver>, hay que crear el IObserver.
  this->suscriptos.push_back(suscriptor);
}

void Suscripciones::eliminar(IObserver* suscriptor) {
  int i = 0;
  while ((i < this->suscriptos.size()) && (this->suscriptos[i] != suscriptor))
    i++;
  if (i < this->suscriptos.size())
    this->suscriptos.erase(this->suscriptos.begin()+i);
}

void Suscripciones::nuevaEvaluacion(Evaluacion* evaluacion) {
  Notificacion* nuevaNotificacion = new Notificacion(evaluacion);
  for (int i = 0; i < this->suscriptos.size(); i++)
    this->suscriptos[i]->notificar(nuevaNotificacion);
  nuevaNotificacion->setCantNotificados(this->suscriptos.size());
  evaluacion->setNotificacion(nuevaNotificacion);
}