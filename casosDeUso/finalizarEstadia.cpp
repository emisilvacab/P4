#include "finalizarEstadia.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

void finalizarEstadia(Fabrica* fabrica){
  IControladorHostal* iControladorHostal = fabrica->getIControladorHostal();
  IControladorReserva* iControladorReserva = fabrica->getIControladorReserva();
  cout << "Hostales: " << endl;
  map<string,DTHostal> hostales = iControladorHostal->obtenerHostales();
  for (map<string,DTHostal>::iterator itHos = hostales.begin(); itHos != hostales.end(); itHos++) 
    cout << itHos->second;
  cout << "Ingrese el nombre del hostal: ";
  cin.ignore(1,'\n');
  string nombre;
  getline(cin,nombre);
  iControladorHostal->seleccionarHostal(nombre);
  cout << "Ingrese el email del huésped: ";
  string email;
  cin >> email;
  iControladorReserva->seleccionarEstadiaActiva(email);
  iControladorReserva->finalizarEstadia();
  cout << "Estadía finalizada! " << endl;
}