#ifndef utils_h
#define utils_h

#include <string.h>
#include <iostream>

using std::string;
using std::istream;

enum EstadoReserva
{
  Abierta,
  Cerrada,
  Cancelada
};

enum TipoCargo
{
  Administracion,
  Limpieza,
  Recepcion,
  Infraestructura
};

TipoCargo obtenerCargo(string cargoIngresado);
string cargoAString(TipoCargo cargoIngresado);

istream& operator>> (istream& in, TipoCargo& estado);

#endif