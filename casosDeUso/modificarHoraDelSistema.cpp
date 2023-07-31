#include "modificarHoraDelSistema.h"

using std::cin;
using std::cout;
using std::endl;

void modificarHoraDelSistema(Fabrica* fabrica){
   IHoraDelSistema* interfazHoraDelSistema = fabrica->getIHoraDelSistema();
   
   int hora, dia, mes, anio;
  
   cout << "Ingrese nueva hora del sistema: \n" << "Hora: ";
   cin >> hora;
   cout << "Dia: ";
   cin >> dia;
   cout << "Mes: ";
   cin >> mes;
   cout << "Año: ";
   cin >> anio;
   DTFecha nuevaHora = DTFecha(hora, dia , mes , anio);

   interfazHoraDelSistema->setFecha(nuevaHora);
   cout << "Nueva fecha: ";
   cout << nuevaHora <<endl;


}
