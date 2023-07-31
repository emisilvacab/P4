#ifndef Reserva_h
#define Reserva_h

#include <string.h>
#include <iostream>
#include <vector>
#include "Habitacion.h"
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTReserva.h"
#include "../utils.h"

using std::string;
using std::vector;

class Habitacion;
class Estadia;

class Reserva {
  private:
    int codigo; 
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    Habitacion* habitacion;
    vector<Estadia*> estadias;
    Hostal* hostal;
    //coleccion de estadias;
  public:
    Reserva();
    virtual ~Reserva();
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    Habitacion* getHabitacion();
    virtual DTReserva* getDatos()=0;
    vector<Estadia*> getEstadias();
    vector<Estadia*> getEstadiasFinalizadas();
    Hostal* getHostal();
    void setCodigo(int codigoIngresado);
    void setCheckIn(DTFecha checkInIngresado);
    void setCheckOut(DTFecha checkOutIngresado);
    void setEstado(EstadoReserva estadoIngresado);
    void setHabitacion(Habitacion* habitacionIngresada);
    void setHostal(Hostal* hostal);
    virtual float getCosto()=0;
    void agregarEstadia(Estadia* estadiaIngresada);
    void destruirEstadias();
    virtual void removerReservaDeHuespedes()=0;
};

#endif