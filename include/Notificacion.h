#ifndef Notificacion_h
#define Notificacion_h

#include "Evaluacion.h"

class Notificacion{
  private:
    Evaluacion* evaluacion;
    int cantNotificados;
  public:
    Notificacion(Evaluacion* evaluacionIngresado); //falta cant, pero se setea despues de notificar a todos los suscriptos
    Evaluacion* getEvaluacion();
    int getCantNotificados();
    void setCantNotificados(int cantIngresado);
    void setEvaluacion(Evaluacion* evaluacionIngresado);
};

#endif 