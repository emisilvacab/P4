#include "DTReservaGrupal.h"

using std::endl;

DTReservaGrupal::DTReservaGrupal(int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, EstadoReserva estadoIngresado, float costoIngresado, map<string,DTHuesped> huespedesIngresado, int numHabitacionIngresado) {
  this->setCodigo(codigoIngresado);
  this->setCheckIn(checkInIngresado);
  this->setCheckOut(checkOutIngresado);
  this->setEstado(estadoIngresado);
  this->setCosto(costoIngresado);
  this->huespedes = huespedesIngresado;
  this->setNumHabitacion(numHabitacionIngresado);
}

map<string,DTHuesped> DTReservaGrupal::getHuespedes(){
  return this->huespedes;
}

void DTReservaGrupal::setHuespedes(map<string,DTHuesped> huespedesIngresado){
  this->huespedes = huespedesIngresado;
}

void DTReservaGrupal::printReserva(ostream &o) {
  o <<"TipoReserva: Grupal"<< endl;
  o << "Código: " << this->getCodigo() << endl;
  o <<"FechaCheckIn: " << this->getCheckIn().getHora() << "hs " << this->getCheckIn().getDia() <<"/"<< this->getCheckIn().getMes() <<"/"<< this->getCheckIn().getAnio()<<endl;
  o <<"FechaCheckOut: "<< this->getCheckOut().getHora() << "hs "<< this->getCheckOut().getDia() <<"/"<< this->getCheckOut().getMes() <<"/"<< this->getCheckOut().getAnio()<<endl;
  o <<"Habitación: "<< this->getNumHabitacion() << endl;
  o <<"Costo: $" << this->getCosto() << endl;
  o <<"Huespedes:" << endl;
  for (map<string,DTHuesped>::iterator it = this->huespedes.begin(); it != this->huespedes.end(); ++it) {
    o << it->second.getNombre();
    if (it->second.getEsFinger())
      o <<" - Es Finger";
    else 
      o << " - No es Finger";
    o << endl;
  }
  o<<endl; 
}
