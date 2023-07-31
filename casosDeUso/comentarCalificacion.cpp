#include "comentarCalificacion.h"

#include <iostream>

using std::cout;
using std::cin;
using std::getline;

void comentarCalificacion(Fabrica* fabrica){
  string email;
  cout << "Ingrese email de empleado: ";
  cin >> email;
  IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
  interfazControladorUsuario->marcarHostalEmpleado(email);

  IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();
  vector<DTEvaluacion> evaluaciones = interfazControladorHostal->obtenerEvaluacionesSinRespuesta();
  if (evaluaciones.size() > 0){
    int numero;
    for(numero = 0; numero < evaluaciones.size(); numero++)
      cout << numero+1 << ")\n" << evaluaciones[numero];
    cout << "Ingrese numero de evaluacion que desea responder: ";
    cin >> numero;
    interfazControladorHostal->seleccionarEvaluacionSR(evaluaciones[numero-1]);
    cout<< "Ingrese la respuesta que desea realizar: ";
    string respuesta;
    cin.ignore(1,'\n');
    getline(cin,respuesta);
    interfazControladorHostal->comentarCalificacion(respuesta);
    cout << "Evaluacion respondida!\n";
  }
  else 
    cout << "No hay evaluaciones sin responder\n";
}