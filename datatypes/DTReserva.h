#ifndef DTReserva_h
#define DTReserva_h

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "DTFecha.h"
#include "../utils.h"

using std::string;
using std::ostream;

class DTReserva{
  protected:
    int codigo;
    DTFecha checkIn, checkOut;
    EstadoReserva estado;
    float costo;
    int numHabitacion;

  public:
    DTReserva();
    virtual ~DTReserva();
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    float getCosto();
    int getNumHabitacion();
    void setCodigo(int codigoIngresado);
    void setCheckIn(DTFecha checkInIngresado);
    void setCheckOut(DTFecha checkOutIngresado);
    void setEstado(EstadoReserva estadoIngresado);
    void setCosto(float costoIngresado);
    void setNumHabitacion(int numHabitacionIngresado);
    friend ostream &operator << (ostream &output, DTReserva &reserva); 
    virtual void printReserva(ostream &output) = 0;
};

#endif