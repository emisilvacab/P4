#ifndef DTEvaluacion_h
#define DTEvaluacion_h

#include <iostream>
#include <stdio.h>
#include <string>
#include "DTFecha.h"

using std::string;
using std::ostream;

class DTEvaluacion {
  private:
    int calificacion;
    string comentario, respuesta;
    DTFecha fecha;
    string mailAutor;
  protected: 
    void printEvaluacion(ostream &o);
  public:
    DTEvaluacion(int calificacionIngresado, string comentarioIngresado, string respuestaIngresado, DTFecha fechaIngresado);
    int getCalificacion();
    string getComentario();
    string getRespuesta();
    DTFecha getFecha();
    string getMailAutor();
    void setMailAutor(string mailAutorIngresado);
    friend ostream &operator << (ostream &output, DTEvaluacion &evaluacion);
};


#endif