#include "consultaEstadia.h"

#include <iostream>
#include "../datatypes/DTEstadia.h"

using std::cout;
using std::cin;
using std::getline;

void consultaEstadia(Fabrica* fabrica){
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
  DTHostal hostal = interfazControladorHostal->obtenerHostal(nombre);
  interfazControladorHostal->seleccionarHostal(nombre);
  vector<DTEstadia> estadias = interfazControladorHostal->obtenerEstadias();
  if (estadias.size() > 0){
    cout << "Estadias del hostal " << nombre << ":\n\n";
    for(int i = 0; i < estadias.size(); i++){
      cout << i+1 << ")\n" << estadias[i];
    }
    int numero;
    cout << "Ingrese numero de estadia que desea consultar: ";
    cin >> numero;
    numero--;
    while (numero >= estadias.size() && numero < 0){
      cout << "Ingrese numero de estadia nuevamente: ";
      cin >> numero;
    }
    
    IControladorReserva* interfazControladorReserva = fabrica->getIControladorReserva();
    IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
    DTHuesped huesped = interfazControladorUsuario->obtenerHuesped(estadias[numero].getEmail());
    bool tieneEvaluacion = interfazControladorReserva->seleccionarEstadia(estadias[numero].getEmail(), estadias[numero].getCodigo());
    
    cout << "Estadia seleccionada:\n";
    cout << "Nombre del huesped: " << huesped.getNombre() << "\n";  
    cout << estadias[numero];
    cout << "Hostal: " << hostal.getNombre() << "\nDireccion: " << hostal.getDireccion() << "\nTelefono: " << hostal.getTelefono() << "\n\n";
    
    string palabra;
    if (tieneEvaluacion) {
      cout << "Desea ver evaluacion? (si/no) ";
      cin >> palabra;
      if (palabra == "si"){
        DTEvaluacion evaluacion = interfazControladorReserva->obtenerEvaluacionAsociada();
        cout << evaluacion << "\n";
      }
    }
    
    cout << "Desea ver informacion de la reserva asociada? (si/no) ";
    cin >> palabra;
    if (palabra == "si"){
      DTReserva* reserva = interfazControladorReserva->obtenerReservaAsociada();
      cout << *reserva;
      delete reserva;
    }
    
  }
  else
    cout << "No hay estadias para este hostal\n";
}