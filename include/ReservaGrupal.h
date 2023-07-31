#ifndef ReservaGrupal_h
#define ReservaGrupal_h

#include "Reserva.h"
#include "Huesped.h"
#include "Hostal.h"
#include "../datatypes/DTReservaGrupal.h"
#include <string.h>
#include <iostream>
#include <map>

using std::string;
using std::map;

class ReservaGrupal: public Reserva{
  private:
    int cantHospedados;
    map<string, Huesped*> huespedes;
  public:
    ReservaGrupal(int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, Habitacion* habitacion, EstadoReserva estadoIngresado, map<string, Huesped*> huespedesIngresado, Hostal* hostalIngresado);
    map<string, Huesped*> getHuespedes();
    void setHuespedes(map<string, Huesped*> huespedesIngresado);
    int getCantHospedados();
    void setCantHospedados(int cantHospedadosIngresado); 
    DTReserva* getDatos();
    float getCosto();
    void removerReservaDeHuespedes();
};

#endif