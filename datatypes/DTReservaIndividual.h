#ifndef DTReservaIndividual_h
#define DTReservaIndividual_h

#include <string.h>
#include <iostream>
#include "DTReserva.h"
#include "DTHuesped.h"

using std::string;

class DTReservaIndividual: public DTReserva{
  private:
    DTHuesped huesped;
  public:
    DTReservaIndividual(int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, EstadoReserva estadoIngresado, float costoIngresado, DTHuesped huespedIngresado, int numHabitacionIngresado);
    DTHuesped getHuesped();
    void printReserva(ostream &output);
};

#endif