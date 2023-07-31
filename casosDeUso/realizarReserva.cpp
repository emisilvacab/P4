#include "realizarReserva.h"
#include <iostream>

using std::cout;
using std::cin;

void realizarReserva(Fabrica* fabrica){
  try{
    IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();
    map<string,DTHostalCalificacion> hostales = interfazControladorHostal->obtenerHostalesCalificacion();
    cout << "Hostales disponibles:\n";
    map<string,DTHostalCalificacion>::iterator itHost;
    for(itHost = hostales.begin(); itHost != hostales.end(); itHost++){
      cout << itHost->second;
      cout << "\n";
    }
    
    cout << "Ingrese nombre del hostal deseado: ";
    cin.ignore(1,'\n');
    string nombreHostal;
    getline(cin,nombreHostal);
    interfazControladorHostal->seleccionarHostal(nombreHostal);
    int hora, dia, mes, anio;
    
    cout << "Ingrese fecha de check in: \n" << "Hora: ";
    cin >> hora;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;
    DTFecha checkIn = DTFecha(hora, dia , mes , anio);
    cout << "Ingrese fecha de check out: \n" << "Hora: ";
    cin >> hora;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;
    DTFecha checkOut = DTFecha(hora, dia , mes , anio);
    
    map<int, DTHabitacion> habitaciones = interfazControladorHostal->obtenerHabitacionesDisponibles(checkIn, checkOut);
    map<int, DTHabitacion>::iterator itHab;
    if (habitaciones.size() ==0)
      throw std::invalid_argument("No hay habitaciones disponibles");
    cout << "Habitaciones disponibles: \n";
    for(itHab = habitaciones.begin(); itHab != habitaciones.end(); itHab++){
      cout << "Habitación número " << itHab->second.getNumero() << "\n";
    }
    
    cout << "Ingrese número de la habitación deseada: ";
    int numero;
    cin >> numero;
    interfazControladorHostal->seleccionarHabitacion(numero);
  
    IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
    vector<string> huespedes = interfazControladorUsuario->obtenerHuespedes();
    cout << "Ingrese el email del huesped que realiza la reserva: ";
    string email;
    cin >> email;
    interfazControladorUsuario->seleccionarHuesped(email);
    
    cout << "¿Desea que la reserva sea grupal? (si/no): ";
    string grupal;
    cin >> grupal;
    while (grupal == "si" | grupal == "Si") {
      vector<string> huespedes = interfazControladorUsuario->obtenerHuespedes();
      cout << "Ingrese el email del huesped que forma parte de la reserva: ";
      cin >> email;
      interfazControladorUsuario->seleccionarHuesped(email);
      cout << "¿Desea agregar más huespedes? (si/no): ";
      cin >> grupal;
    }
    cout << "¿Desea confirmar la reserva? (si/no): ";
    string confirma;
    cin >> confirma; 
    if (confirma == "si" | confirma == "Si") {
      IControladorReserva* interfazControladorReserva = fabrica->getIControladorReserva();
      interfazControladorReserva->confirmarReserva();
      cout<<"Reserva realizada!";
    }
    else cout<<"Reserva cancelada!";
    interfazControladorUsuario->liberarHuespedesRecordados();
  }catch (std::invalid_argument &e){
    cout<< std::endl <<e.what() <<std::endl;
  }
}

