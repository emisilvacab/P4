#ifndef Suscripciones_h
#define Suscripciones_h

class DTEmpleado; //fwrd?
//class DTIObserver; //fwrd?

#include "../datatypes/DTEmpleado.h"
#include "../include/Fabrica.h"
#include "../include/Notificacion.h"

#include <string.h>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

class IObserver;
class Evaluacion;

class Suscripciones {
  private:
    static Suscripciones* suscripciones;
    vector<IObserver*> suscriptos;
    Suscripciones();
  public:
    static Suscripciones* getInstance();
    vector<IObserver*> getSuscriptos();
    void suscribir(IObserver* suscriptor);
    void eliminar(IObserver* suscriptor);
    void nuevaEvaluacion(Evaluacion* evaluacion);
};

#endif