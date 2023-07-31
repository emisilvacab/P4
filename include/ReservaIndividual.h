#ifndef ReservaIndividual_h
#define ReservaIndividual_h

#include <string.h>
#include <iostream>
#include "Reserva.h"
#include "Huesped.h"
#include "../datatypes/DTReservaIndividual.h"

using std::string;

class ReservaIndividual: public Reserva{
  private:
    Huesped* huesped;
  public:
    ReservaIndividual(int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, Habitacion* habitacionIngresado, EstadoReserva estadoIngresado, Huesped* huespedIngresado, Hostal* hostalIngresado);
    Huesped* getHuesped();
    float getCosto();
    DTReserva* getDatos();
    void removerReservaDeHuespedes();
};

#endif