#ifndef Evaluacion_h
#define Evaluacion_h

#include <string.h>
#include <iostream>
#include "Estadia.h"
#include "Empleado.h"
#include "Hostal.h"

#include "../datatypes/DTFecha.h"
#include "../datatypes/DTEvaluacion.h"
#include "../include/Notificacion.h"

using std::string;

class Evaluacion{
  private: 
    int calificacion;
    string comentario;
    string respuesta;
    DTFecha fecha;
    Estadia* estadia;
    Hostal* hostal;
    Empleado* empleado;
    Notificacion* notificacion;
  public:
    Evaluacion(int calificacionIngresado, string comentarioIngresado, DTFecha fechaIngresado, Estadia* estadiaIngresado, Hostal* hostalIngresado);
    int getCalificacion();
    string getComentario();
    string getRespuesta();
    DTFecha getFecha();
    Estadia* getEstadia();
    Hostal* getHostal();
    DTEvaluacion getDatos();
    Empleado* getEmpleado();
    Notificacion* getNotificacion();
    bool isCalificada(); //PARA SABER SI STRING RESPUESTA ES DISINTO DE VACIO;
    void setRespuesta(string respuestaIngresado);
    void setEmpleado(Empleado* empleado);
    void setNotificacion(Notificacion* notificacionIngresado);
};

#endif