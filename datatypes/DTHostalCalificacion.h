#ifndef DTHostalCalificacion_h
#define DTHostalCalificacion_h

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>

using std::string;
using std::ostream;

class DTHostalCalificacion {
  private:
    string nombre, direccion, telefono;
    float calificacionPromedio;

  public:
    DTHostalCalificacion(string nombreIngresado, string direccionIngresado, string telefonoIngresado, float calificacionPromedioIngresado);
    DTHostalCalificacion();
    string getNombre();
    string getDireccion();
    string getTelefono();
    float getCalificacionPromedio();
    friend ostream &operator << (ostream &output, DTHostalCalificacion &hostal);
};

#endif