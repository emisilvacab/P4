#include "consultarTop3DeHostales.h"

using std::cout;
using std::cin;
using std::string;
using std::getline;

void consultarTop3DeHostales(Fabrica* fabrica){
  IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();
  string nombreIngresado, palabra;
  
  vector<string> hostales = interfazControladorHostal->obtenerTop();
  for (int i = 0; i < hostales.size(); i++){
    cout << hostales[i] + "\n";
  }
  cout << "Desea ver detalles de algun hostal? (si/no) ";
  cin >> palabra;
  if (palabra == "si"){
    cout << "Ingrese nombre del hostal: ";
    cin.ignore(1,'\n');
    getline(cin,nombreIngresado);
    if (interfazControladorHostal->existsHostal(nombreIngresado)){
      vector<DTEvaluacion> evaluaciones = interfazControladorHostal->obtenerEvaluacionesHostal(nombreIngresado);
      for (int i = 0; i < evaluaciones.size(); i++){
        cout << evaluaciones[i];
        cout << "\n";
      }
    }
    else
      cout << "Hostal no existe intente nuevamente\n";
  }
}