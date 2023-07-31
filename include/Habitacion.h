#ifndef Habitacion_h
#define Habitacion_h

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "TipoConsumo.h"
#include "../datatypes/DTFecha.h"
#include "Hostal.h"

using std::vector;
using std::map;

class Reserva;

class Habitacion {
  private:
    int numero, capacidad;
    float precio;
    Hostal* hostal;
    map<string, TipoConsumo*> tipoConsumos;
    map<int, Reserva*> reservas;
  public:
    Habitacion(int numeroIngresado, int capacidadIngresado, float precioIngresado, Hostal* hostalIngresado);
    int getNumero();
    int getCapacidad();
    float getPrecio();
    Hostal* getHostal();
    map<string, TipoConsumo*> getTipoConsumos();
    map<int, Reserva*> getReservas();
    void addReserva(Reserva* reservaIngresado);
    void setNumero(int numeroIngresado);
    void setCapacidad(int capacidadIngresado);
    void setPrecio(float precioIngresado);
    bool isDisponible(DTFecha checkIn, DTFecha checkOut);
    void removerReserva(Reserva* reserva);
};

#endif