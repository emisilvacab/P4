#include "registrarEstadia.h"

using std::cout;
using std::cin;
using std::string;
using std::getline;

void registrarEstadia(Fabrica* fabrica){
  IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();
  IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
  IControladorReserva* interfazControladorReserva = fabrica->getIControladorReserva();
  cout << "Hostales disponibles: " << endl;
  map<string, DTHostal> hostales = interfazControladorHostal->obtenerHostales();
  map<string, DTHostal>::iterator i;
  for (i = hostales.begin(); i != hostales.end(); i++){
    cout << "-" << i->second;
  }
  
  cout << "Ingrese el nombre del hostal deseado: ";
  cin.ignore(1,'\n');
  string nombre;
  getline(cin,nombre);
  interfazControladorHostal->seleccionarHostal(nombre);

  cout << "Ingrese el email del usuario: ";
  string email;
  cin >> email;
  cout << "Reservas no canceladas: " << endl << endl;
  list<DTReserva*> reservasNoCanceladas = interfazControladorUsuario->obtenerReservasNoCanceladas(email);
  list<DTReserva*>::iterator it;
  for (it = reservasNoCanceladas.begin(); it !=  reservasNoCanceladas.end(); it++){
    cout << *(*it);
    //FALTA HACER DELETE A LAS DTRESERVA EN LA LISTA
  }
  cout << "Ingrese el código de la reserva: ";
  int codigo;
  cin >> codigo;
  interfazControladorReserva->seleccionarReserva(codigo);
  interfazControladorReserva->crearEstadia();
      for(DTReserva* res : reservasNoCanceladas){
     delete res;
  }
  reservasNoCanceladas.clear();
  cout << "Estadía registrada!" << endl; 
}