#include "consultaReserva.h"

using std::cout;
using std::cin;
using std::string;
using std::getline;


void consultaReserva(Fabrica* fabrica) {
  IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();
  map<string, DTHostal> hostales = interfazControladorHostal->obtenerHostales();
  cout << "Hostales del sistema:\n";
  for(map<string, DTHostal>::iterator itHos = hostales.begin(); itHos != hostales.end(); itHos++) {
    cout << itHos->second << "\n";
  } 
  cout << "Ingrese el nombre del hostal: ";
  string nombre;
  cin.ignore(1,'\n');
  getline(cin,nombre);
  //se puede agregar un try para ver si el hostal tiene reservas
  interfazControladorHostal->seleccionarHostal(nombre);
  vector<DTReserva*> reservas = interfazControladorHostal->obtenerReservas();
  if (reservas.size() >0){
    cout << "Las reservas del hostal son:\n";
    cout << "\n";
    for(int i = 0; i < reservas.size(); i++) {
      cout << *reservas[i];
      delete reservas[i];
    }
  }
  else cout<<"No hay reservas!";
}