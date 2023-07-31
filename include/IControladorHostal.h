#ifndef IControladorHostal_h
#define IControladorHostal_h

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "../datatypes/DTFecha.h"
#include "../datatypes/DTHostal.h"
#include "../datatypes/DTHostalCalificacion.h"
#include "../datatypes/DTHabitacionEvaluacion.h"
#include "../datatypes/DTTipoConsumo.h"
#include "../datatypes/DTHabitacion.h"
#include "../datatypes/DTEvaluacion.h"
#include "../datatypes/DTEstadia.h"
#include "../include/Hostal.h"
#include "../include/TipoConsumo.h"
#include "../include/Habitacion.h"
#include "../include/Evaluacion.h"

using std::string;
using std::vector;
using std::map;

class IControladorHostal {    
  public:
    //PARA EXCPECIONES 
    virtual bool existsHostal(string nombreIngresado)=0;
    //Alta de Hostal
    virtual void ingresarDatosHostal(DTHostal data)=0;
    virtual void confirmarAltaHostal()=0;
    //Alta de Habitacion
    virtual map<string, DTHostal> obtenerHostales()=0;
    virtual void seleccionarHostal(string nombre)=0;
    virtual void confirmarAltaHabitacion(int numero, int capacidad, float precio)=0;
    virtual bool hayLugar() = 0;
    // Consultar top 3 de hostales  
    virtual vector<string> obtenerTop()=0;
    virtual vector<DTEvaluacion> obtenerEvaluacionesHostal(string nombreIngresado)=0;
    //Realizar Reserva
    virtual map<string, DTHostalCalificacion> obtenerHostalesCalificacion()=0;
    virtual map<int, DTHabitacion> obtenerHabitacionesDisponibles(DTFecha checkIn, DTFecha checkOut)=0;
    virtual void seleccionarHabitacion(int num)=0;
    //Consulta de Reserva
    virtual vector<DTReserva*> obtenerReservas()=0;
    //Consulta de Hostal
    virtual DTHostalCalificacion obtenerHostalCalificacion()=0;
    virtual vector<DTHabitacionEvaluacion> obtenerHabitacionEvaluacion()=0;
    virtual vector<DTEstadia> obtenerEstadias()=0;
    //Consulta Estadia
    virtual DTHostal obtenerHostal(string nombre)=0;
    virtual void setCheckInRecordado(DTFecha checkInIngresado)=0;
    virtual void setCheckOutRecordado(DTFecha checkOutIngresado)=0;
    //Comentar Calificacion
    virtual vector<DTEvaluacion> obtenerEvaluacionesSinRespuesta()=0;
    virtual void seleccionarEvaluacionSR(DTEvaluacion evaluacion)=0;
    virtual void comentarCalificacion(string respuesta)=0;
};

#endif