#ifndef DTHabitacionEvaluacion_h
#define DTHabitacionEvaluacion_h

#include <map>
#include <vector>
#include <list>
#include <iostream>
#include "DTEvaluacion.h"

using std::map;
using std::vector;

class DTHabitacionEvaluacion {
  private:
    int numero, capacidad;
    float precio;

    vector<DTEvaluacion> evaluaciones;

  public:
    DTHabitacionEvaluacion(int numeroIngresado, int capacidadIngresado, float precioIngresado, vector<DTEvaluacion> evaluacionesIngresado);

    int getNumero();
    int getCapacidad();
    float getPrecio();
    vector<DTEvaluacion> getEvaluaciones();
    friend ostream &operator << (ostream &output, DTHabitacionEvaluacion &habitacion);
};

#endif