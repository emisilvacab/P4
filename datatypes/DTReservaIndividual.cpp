#include "DTReservaIndividual.h"

using std::endl;

DTReservaIndividual::DTReservaIndividual(int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado,  EstadoReserva estadoIngresado, float costoIngresado, DTHuesped huespedIngresado, int numHabitacionIngresado) {
  this->setCodigo(codigoIngresado);
  this->setCheckIn(checkInIngresado);
  this->setCheckOut(checkOutIngresado);
  this->setEstado(estadoIngresado);
  this->setCosto(costoIngresado);
  this->setNumHabitacion(numHabitacionIngresado);
  this->huesped = huespedIngresado;
}

DTHuesped DTReservaIndividual::getHuesped() {
  return this->huesped;
}

void DTReservaIndividual::printReserva(ostream &o){
  o <<"TipoReserva: Individual"<< endl;
  o << "Código: " << this->getCodigo() << endl;
  o <<"FechaCheckIn: "<< this->getCheckIn().getHora() << "hs "<< this->getCheckIn().getDia() <<"/"<< this->getCheckIn().getMes() <<"/"<< this->getCheckIn().getAnio()<<endl;
  o <<"FechaCheckOut: "<< this->getCheckOut().getHora() << "hs "<< this->getCheckOut().getDia() <<"/"<< this->getCheckOut().getMes() <<"/"<< this->getCheckOut().getAnio()<<endl;
  o <<"Habitación: "<< this->getNumHabitacion() << endl;
  o <<"Costo: $" << this->getCosto() << endl;
  o <<"Huespedes:" << endl;
  o << this->getHuesped().getNombre(); 
  if (this->getHuesped().getEsFinger())
    o <<" - Es Finger";
  else 
    o << " - No es Finger";
  o << endl;
  o << endl;
}
