#include "DTEstadia.h"

using std::endl;

  DTEstadia::DTEstadia(string emailIngresado, int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, bool promoIngresado, float totalConsumoIngresado){
    this->email = emailIngresado;
    this->codigo = codigoIngresado;
    this->checkIn = checkInIngresado;
    this->checkOut = checkOutIngresado;
    this->promo = promoIngresado;
    this->totalConsumo = totalConsumoIngresado; 
  }

  string DTEstadia::getEmail(){
    return this->email;
  }

  int DTEstadia::getCodigo(){
    return this->codigo;
  }

  DTFecha DTEstadia::getCheckIn(){
    return this->checkIn;
  }

  DTFecha DTEstadia::getCheckOut(){
    return this->checkOut;
  }

  bool DTEstadia::getPromo(){
    return this->promo;
  }

  float DTEstadia::getTotalConsumo(){
    return this->totalConsumo;
  }

ostream &operator << (ostream &output, DTEstadia &estadia){
  output << "Email de Huesped: " << estadia.email << endl;
  output << "Codigo de Reserva: " << estadia.codigo << endl;
  output << "CheckIn: " << estadia.checkIn << endl;
   if (estadia.checkOut.getDia() == -1)
    output << "CheckOut: " << "Sin finalizar" << endl;
  else
    output << "CheckOut: " << estadia.checkOut << endl;
  output << "Promo: ";
  if (estadia.promo)
    output << "Si" << endl;
  else
    output << "No" << endl;
  output << "Total Consumido: $" << estadia.totalConsumo << endl << endl;
  return output;
}