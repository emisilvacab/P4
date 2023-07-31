#include "../include/HoraDelSistema.h"

HoraDelSistema * HoraDelSistema::instance = NULL;

HoraDelSistema::HoraDelSistema(){}

HoraDelSistema* HoraDelSistema::getInstance() {
  if (instance == NULL)
    instance = new HoraDelSistema();
  return instance;
}

DTFecha HoraDelSistema::getFecha(){
  return this->fecha;
}

void HoraDelSistema::setFecha(DTFecha fechaIngresada){
  this->fecha = fechaIngresada;
}