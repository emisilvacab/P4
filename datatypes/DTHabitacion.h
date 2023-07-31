#ifndef DTHabitacion_h
#define DTHabitacion_h

#include <string>
#include <iostream>

class DTHabitacion {
  private:
    int numero, capacidad;
    float precio;
  public:
    DTHabitacion(int numeroIngresado, int capacidadIngresado, float precioIngresado);
    DTHabitacion();
    int getNumero();
    int getCapacidad();
    float getPrecio();
};

#endif