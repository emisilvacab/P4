#include "../include/Fabrica.h"

IControladorUsuario* Fabrica::getIControladorUsuario(){
  return ControladorUsuario::getInstance();
}

IControladorHostal* Fabrica::getIControladorHostal(){
  return ControladorHostal::getInstance();
}

IControladorReserva* Fabrica::getIControladorReserva(){
  return ControladorReserva::getInstance();
}

IHoraDelSistema* Fabrica::getIHoraDelSistema(){
  return HoraDelSistema::getInstance();
}