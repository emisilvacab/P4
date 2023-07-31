#ifndef DTReservaGrupal_h
#define DTReservaGrupal_h

#include <string.h>
#include <iostream>
#include "DTReserva.h"
#include "DTHuesped.h"
#include <map>
#include <list>
#include <set>

using std::map;

class DTReservaGrupal: public DTReserva {
  private:
    map<string,DTHuesped> huespedes;
  public:
    DTReservaGrupal(int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, EstadoReserva estadoIngresado, float costoIngresado,  map<string, DTHuesped> huespedesIngresado, int numHabitacionIngresado);
    map<string,DTHuesped> getHuespedes();
    void setHuespedes(map<string,DTHuesped> huespedesIngresado);
    void printReserva(ostream &output);
};

#endif