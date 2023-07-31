#include "suscribirseNotificaciones.h"

using std::cout;
using std::cin;
using std::string;

void suscribirseNotificaciones(Fabrica* fabrica){
  IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
  map<string, DTEmpleado> empleados = interfazControladorUsuario->obtenerEmpleados();
  cout<<"Los emails de los empleados registrados en el sistema son:"<<endl;
  map<string, DTEmpleado>::iterator it;
  for(it = empleados.begin(); it!=empleados.end(); ++it)
    cout<<"-"<<it->first<<endl;
  string email;
  cout << "Ingrese el email del empleado que desea suscribir: ";
  cin >> email;
  /*
  map<string, DTEmpleado>::iterator ingresado;
  ingresado = empleados.end();
  for(it = empleados.begin(); it!=empleados.end(); ++it)
    if(it->second.getEmail() == email)
      ingresado = it;
  if(ingresado == empleados.end())
    cout<<"El email ingresado es incorrecto";
  else{
    Suscripciones* suscripciones = Suscripciones::getInstance();
    suscripciones->suscribir(ingresado->second); //el sistema ya tiene recordado al usuario
    */
  interfazControladorUsuario->suscribirEmpleado(email);
  cout<<"Empleado suscripto!\n";
  
  
}