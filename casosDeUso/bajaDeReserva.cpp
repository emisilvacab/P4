#include "bajaDeReserva.h"


using std::cout;
using std::cin;
using std::string;
using std::getline;

void bajaDeReserva (Fabrica* fabrica) {
  IControladorHostal* controladorHostal = fabrica->getIControladorHostal();
  IControladorReserva* controladorReserva = fabrica->getIControladorReserva();
  cout << "Hostales disponibles:\n";
  map<string, DTHostal> hostales = controladorHostal->obtenerHostales();
  for(map<string, DTHostal>::iterator itHos = hostales.begin(); itHos != hostales.end(); itHos++) {
    cout << "- " << itHos->second;
  } 
 
  cout << "Ingrese el nombre del hostal deseado: ";
  cin.ignore(1,'\n');
  string nombre;
  getline(cin,nombre);
  controladorHostal->seleccionarHostal(nombre);
  vector <DTReserva*> reservas = controladorHostal->obtenerReservas();
  if (reservas.size() != 0) {
    cout << "Las reservas del sistema son:\n";
    cout << "\n";
    for(int i = 0; i < reservas.size(); i++) {
      cout << *reservas[i];
      delete reservas[i];
    }
    
    cout << "Ingrese el código de la reserva: ";
    int codigo;
    cin >> codigo;
    controladorReserva->seleccionarReservaPorHostal(codigo);
    
    cout << "Desea confirmar la baja? ";
    string palabra;
    cin >> palabra;
    if (palabra=="si"){
      controladorReserva->confirmarBajadeReserva(); //delete data
      cout << "Baja realizada!";
    }
    else{
      cout << "Baja cancelada!";
    }
  }
  else {
    cout << "No hay reservas para el hostal seleccionado.";
  }
}