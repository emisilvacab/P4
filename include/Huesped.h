#ifndef Huesped_h
#define Huesped_h

#include <string.h>
#include <iostream>
#include <list>
#include <vector>
#include "Usuario.h"

#include "../datatypes/DTReserva.h"
#include "../datatypes/DTHuesped.h"

using std::string;
using std::list;
using std::vector;

class Estadia;

class Huesped: public Usuario{
  private:
    bool esFinger;
    map<int, Reserva*> reservas;
    vector<Estadia*> estadias;
  public:
    Huesped(string nombreIngresado, string emailIngresado, string passwordIngresado, bool esFingerIngresado);
    map<int,Reserva*> getReservas();
    void setReservas(map<int,Reserva*> reservasIngresado);
    bool getEsFinger();
    void setEsFinger(bool esFingerIngresado);
    list<DTReserva*> obtenerReservasNoCanceladas();
    DTHuesped getDatos();
    vector<Estadia*> getEstadias();
    void agregarEstadia(Estadia* estadia);
    void addReserva(Reserva* reservaIngresado);
    void removerEstadia(Estadia* estadia);
    void removerReserva(Reserva* reserva);
};


#endif