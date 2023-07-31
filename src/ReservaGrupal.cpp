#include "../include/ReservaGrupal.h"
ReservaGrupal::ReservaGrupal(int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, Habitacion* habitacionIngresado, EstadoReserva estadoIngresado, map<string, Huesped*> huespedesIngresado, Hostal* hostalIngresado){ 
  this->setCodigo(codigoIngresado);
  this->setCheckIn(checkInIngresado);
  this->setCheckOut(checkOutIngresado);
  this->setEstado(estadoIngresado);
  this->setHabitacion(habitacionIngresado);
  this->huespedes = huespedesIngresado;
  this->setHostal(hostalIngresado);
  //Links
  habitacionIngresado->addReserva(this);
  hostalIngresado->addReserva(this);
  map<string, Huesped*> :: iterator it;
  for(it = huespedesIngresado.begin(); it != huespedesIngresado.end(); ++it) {
    it->second->addReserva(this);
  }
  
}

map<string, Huesped*> ReservaGrupal::getHuespedes(){
  return this->huespedes;
}

int ReservaGrupal::getCantHospedados() {
  return this->cantHospedados;
}

void ReservaGrupal::setCantHospedados(int cantHospedadosIngresado) {
  this->cantHospedados = cantHospedadosIngresado;
}

void ReservaGrupal::setHuespedes(map<string, Huesped*> huespedesIngresados){
  this->huespedes = huespedesIngresados;
}
/*
map<string,Hostal*>::iterator it = this->hostales.begin();
    while((it != this->hostales.end()) && (it->second->getNombre()!=nombre)){
      cout<< "lo busca";
      it++;
    }*/
float ReservaGrupal::getCosto(){
    int cantDias = (this->getCheckOut().getAnio() - this->getCheckIn().getAnio() +1)*12*31 - (this->getCheckIn().getMes() + 11 - this->getCheckOut().getMes())*31 - (this->getCheckIn().getDia() + 31 - this->getCheckOut().getDia());
    map<string, Huesped*>::iterator it = this->huespedes.begin();
    bool hayUnFinger = false, hayDosFingers = false;
    while((it != this->huespedes.end()) && !hayDosFingers){
      if (it->second->getEsFinger()) {
        if (!hayUnFinger)
          hayUnFinger = true;
        else
          hayDosFingers = true;
      }
      ++it;
    }
    float descuento = 1;
    if (hayDosFingers)
      descuento = 0.70; //es lo mismo que restar el 0.30
    return (this->getHabitacion()->getPrecio() * this->huespedes.size() * cantDias) * descuento;
}

DTReserva* ReservaGrupal::getDatos() {
  map <string, DTHuesped> hues;
  for (map<string,Huesped*>::iterator it = this->huespedes.begin(); it != this->huespedes.end(); it++) {
    hues.insert({it->second->getEmail(),it->second->getDatos()});
  }
  DTReservaGrupal* res = new DTReservaGrupal(this->getCodigo(), this->getCheckIn(), this->getCheckOut(), this->getEstado(), this->getCosto(), hues, this->getHabitacion()->getNumero());
  return res;
}

void ReservaGrupal::removerReservaDeHuespedes() {
  for(map<string,Huesped*>::iterator it = this->huespedes.begin(); it != this->huespedes.end(); it++)
    it->second->removerReserva(this);
}

