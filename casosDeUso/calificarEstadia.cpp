#include "calificarEstadia.h"

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

void calificarEstadia(Fabrica* fabrica) {
  try{
  	//Obtener Hostales y Seleccionar Hostal
  	IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();
  	cout << "Hostales disponibles:\n";
      map<string, DTHostal> hostales = interfazControladorHostal->obtenerHostales();
      map<string, DTHostal>::iterator it;
      for(it = hostales.begin(); it != hostales.end(); it++)
        cout <<"- " <<it->first << "\n";
      cout << "Ingrese el nombre del hostal deseado: ";
      string nombre;
      cin.ignore(1, '\n');
      getline(cin, nombre);
      interfazControladorHostal->seleccionarHostal(nombre);
      
      //Obtener Estadias Finalizadas
      IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
      string emailIngresado;
      cout << "Ingrese el mail del usuario: ";
      cin >> emailIngresado;
      vector<DTEstadia> estadiasFinalizadas = interfazControladorUsuario->obtenerEstadiasFinalizada(emailIngresado);
      if (estadiasFinalizadas.size() ==0)
        throw std::invalid_argument("El huuesped no tiene estadías finalizadas!");
      cout << "Sus estadias finalizadas son:\n";
      for (int i = 0; i < estadiasFinalizadas.size(); i++)
  		  cout << estadiasFinalizadas[i];
  		
      //SeleccionarEstadia
      cout << "Ingrese el codigo asociado a la reserva cuya estadia se va a calificar: ";
      int codigo;
      cin >> codigo;
      IControladorReserva* interfazControladorReserva = fabrica->getIControladorReserva();
      if (interfazControladorReserva->seleccionarEstadia(emailIngresado, codigo))
  		cout << "La estadia ya fue calificada";
  	else {
  		cout << "Ingrese un comentario acerca de la estadia: ";
  		string coment;
      cin.ignore(1,'\n');
      getline(cin,coment);
      cout << "Indique, con un numero del 1 al 5, la calificacion de la estadia: ";
  		int calificacion;
  		cin >> calificacion;
      if (calificacion >= 1 && calificacion <= 5) {
  		  interfazControladorReserva->ingresarCalificacion(coment, calificacion);
  		  cout << "La estadia quedó calificada";
      } else
        cout << "Debe ingresar un numero entre 1 y 5";
  	}
  }catch (std::invalid_argument &e){
    cout<< std::endl <<e.what() <<std::endl;
  }
}
