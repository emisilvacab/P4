#ifndef Hostal_h
#define Hostal_h

#include <string>
#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include "../datatypes/DTEvaluacion.h"
#include "../datatypes/DTHostal.h"
#include "Empleado.h"

using std::string;
using std::map;
using std::vector;

class Evaluacion;
class Habitacion;
class Reserva;
class DTReserva;

class Hostal {
  private:
    string nombre, direccion, telefono;
    map<int, Habitacion*> habitaciones;
    map<string, Empleado*> empleados;
    map<int, Reserva*> reservas;
    vector<Evaluacion*> evaluaciones;
  public:
    //Hostal(string nombreIngresado, string direccionIngresado, string telefonoIngresado, map<int, Habitacion*> habitacionesIngresado);
    Hostal(string nombreIngresado, string direccionIngresado, string telefonoIngresado);//prueba
    string getNombre();
    string getDireccion();
    string getTelefono();
    map<int, Habitacion*> getHabitaciones();
    map<int, Reserva*> getReservas();
    vector<Evaluacion*> getEvaluaciones();
    vector<DTEvaluacion> getDTEvaluaciones();
    map<string, Empleado*> getEmpleados();
    float getPromedio();
    vector<DTReserva*> getDatosReservas();
    DTHostal getDatos();
    void setNombre(string nombreIngresado);
    void setDireccion(string direccionIngresado);
    void setTelefono(string telefonoIngresado);
    void addReserva(Reserva* reservaIngresado);
    void addEmpleado(Empleado* empleadoIngresado);
    void addHabitacion(Habitacion* habitacion);
    void addEvaluacion(Evaluacion* evaluacionIngresado);
    void removerEvaluacion(Evaluacion* evaluacion);
    void removerReserva(Reserva* reserva);
    Habitacion* getHabitacion(int num);
};

#endif