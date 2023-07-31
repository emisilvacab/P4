#include "asignarEmpleadoAHostal.h"

using std::cout;
using std::cin;
using std::string;
using std::getline;

void asignarEmpleadoAHostal(Fabrica* fabrica){
  IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();

  cout << "Hostales disponibles:\n";
  map<string, DTHostal> hostales = interfazControladorHostal->obtenerHostales();
  map<string, DTHostal>::iterator i;
  for(i = hostales.begin(); i != hostales.end(); i++){
    cout<<i->first << std::endl;
  }
  cout<< "\n";
  cout << "Ingrese el nombre del hostal deseado: ";
  cin.ignore(1,'\n');
  string nombre;
  getline(cin,nombre);
  interfazControladorHostal->seleccionarHostal(nombre);

  IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
  map<string, DTEmpleado> empleadosNoAsignados = interfazControladorUsuario->obtenerEmpleadosNoAsignados();
  map<string, DTEmpleado>::iterator it; 

  if (!empleadosNoAsignados.empty())
      cout<<"Los emails de los empleados no asignados son: \n";

  
  for(it = empleadosNoAsignados.begin(); it != empleadosNoAsignados.end(); ++it){
    cout<<"-"<<it->first <<std::endl;
  }
  string email;
  cout << "Ingrese el email del empleado que desea asignar: ";
  cin >> email;
  cout<< "Ingrese el cargo que tendrá el empleado seleccionado: ";
  string strCargo;
  cin>>strCargo;
  interfazControladorUsuario->seleccionarEmpleado(email, obtenerCargo(strCargo));

  cout<< "Desea confirmar la asignación? ";
  cin >> nombre;
  if (nombre=="si" || nombre=="Si"){
    interfazControladorUsuario->confrimarAsignarEmpleadoHostal();
    cout<<"Asignación confirmada! ";
  }
  
}