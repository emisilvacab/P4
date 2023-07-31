   #include "consultaDeNotificaciones.h"

#include <vector>

using std::vector;

void consultaDeNotificaciones(Fabrica* fabrica) {
  IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();
  map<string, DTEmpleado> empleados = interfazControladorUsuario->obtenerEmpleados();
  cout<<"Los emails de los empleados registrados en el sistema son:"<<endl;
  map<string, DTEmpleado>::iterator it;
  for(it = empleados.begin(); it!=empleados.end(); ++it)
    cout<<"-"<<it->first<<endl;
  string email;
  cout << "Ingrese el email del empleado cuyas notificaciones desea consultar: ";
  cin >> email;
  if (interfazControladorUsuario->seleccionarSiEstaSuscrito(email)) {
    vector<DTEvaluacion> notificacionesEmpleado = interfazControladorUsuario->devolverNotificaciones();
    if (notificacionesEmpleado.size() > 0){
      cout << "Las ultimas notificaciones del empleado son:\n";
      for (int i = 0; i < notificacionesEmpleado.size(); i++) {
        cout << "Mail del autor:" << notificacionesEmpleado[i].getMailAutor() << "\n";
        cout << "Calificacion:" << notificacionesEmpleado[i].getCalificacion() << "\n";
        cout << "Comentario:" << notificacionesEmpleado[i].getComentario() << "\n";
        cout << "\n";
      }
    }
    else cout<<"El empleado no tiene notificaciones!";
  } else
    cout << "El empleado no esta suscrito a las notificaciones\n";
}