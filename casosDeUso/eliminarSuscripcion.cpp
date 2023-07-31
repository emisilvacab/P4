#include "eliminarSuscripcion.h"

using std::cout;
using std::cin;
using std::string;

void eliminarSuscripcion(Fabrica* fabrica) {
  IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
  map<string, DTEmpleado> empleados = interfazControladorUsuario->obtenerEmpleados();
  cout<<"Los emails de los empleados registrados en el sistema son:"<<endl;
  map<string, DTEmpleado>::iterator it;
  for(it = empleados.begin(); it!=empleados.end(); ++it)
    cout<<"-"<<it->first<<endl;
  string email;
  cout << "Ingrese el email del empleado cuya suscripcion desea eliminar: ";
  cin >> email;
  interfazControladorUsuario->desuscribirEmpleado(email);
  cout<<"Suscripcion eliminada!\n";
}