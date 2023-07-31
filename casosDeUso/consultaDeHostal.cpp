#include "consultaDeHostal.h"

using std::cout;
using std::cin;
using std::endl;
using std::getline;

void consultaDeHostal(Fabrica* fabrica){
  IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();
  
  cout<<"Hostales disponibles:\n";
  map<string, DTHostal> hostales = interfazControladorHostal->obtenerHostales();
  map<string, DTHostal>::iterator it;
  for(it = hostales.begin(); it != hostales.end(); it++){
    cout<< "- " << it->second.getNombre() <<endl;
  }
  
  cout<<"Ingrese el nombre del hostal deseado: ";
  string entrada;
  cin.ignore(1, '\n');
  getline(cin, entrada);
  
  interfazControladorHostal->seleccionarHostal(entrada);
  
  cout << "\n";
  
  DTHostalCalificacion hostalCalificacion = interfazControladorHostal->obtenerHostalCalificacion();
  cout<< "Hostal:" <<endl;
  cout << hostalCalificacion;
  
  cout<< "Habitaciones:" << endl;
  vector<DTHabitacionEvaluacion> habitacionEvaluacion = interfazControladorHostal->obtenerHabitacionEvaluacion();
  for(DTHabitacionEvaluacion i : habitacionEvaluacion){
    cout << i;
    cout << endl;
  }
  
}
