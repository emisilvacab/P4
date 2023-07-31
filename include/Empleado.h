#ifndef Empleado_h
#define Empleado_h

#include "IObserver.h"
#include "../utils.h"
#include <string.h>
#include <iostream>
#include "Usuario.h"
#include <vector>

using std::string;
using std::vector;

class Evaluacion; //fwrd
class Hostal;

class Empleado: public Usuario, public IObserver {
  private:
    TipoCargo cargo;
    Hostal* hostal;
    vector<Evaluacion*> evaluaciones;
    vector<Notificacion*> notificaciones; //en el caso de uso deja vacio
  public:
    Empleado();
    Empleado(string nombreIngresado, string emailIngresado, string passwordIngresado, TipoCargo cargoIngresado);
    ~Empleado();
    Hostal* getHostal();
    TipoCargo getCargo();
    void setHostal(Hostal* hostalIngresado);
    void setCargo(TipoCargo cargoIngresado);
    vector<Notificacion*> getNotificaciones();
    bool empleadoNoAsignado();
    void linkHostal(Hostal* hostalIngresado, TipoCargo cargoIngresado);
    void addEvaluacion(Evaluacion* evaluacion);
    void removerEvaluacion(Evaluacion* evaluacion);
    void notificar(Notificacion* notificacionIngresada);

    void limpiarNotificaciones(); //clear notificaciones

};

#endif