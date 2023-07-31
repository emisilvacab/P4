#include "altaDeHabitacion.h"

using std::cout;
using std::cin;
using std::string;

void altaDeHabitacion(Fabrica* fabrica){
  try{
    IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();

    cout << "Hostales disponibles:\n";
    map<string, DTHostal> hostales = interfazControladorHostal->obtenerHostales();
    map<string, DTHostal>::iterator it;
    for(it = hostales.begin(); it != hostales.end(); it++)
      cout << it->first << "\n";
    cout << "Ingrese el nombre del hostal deseado: ";
    string nombre;
    cin.ignore(1,'\n');
    getline(cin,nombre);
    interfazControladorHostal->seleccionarHostal(nombre);

    int numero, capacidad;
    float precio;
    cout << "Ingrese el numero de la habitación: ";
    cin >> numero;
    cout << "Ingrese la capacidad de la habitación: ";
    cin >> capacidad;
    cout << "Ingrese el precio de la habitación: ";
    cin >> precio;

    string entrada;
    /*
    cout << "Desea ingresar consumos?: si/no\n";
    string entrada;

    if(entrada=="si"){
      map<string, DTTipoConsumo> consumos = interfazControladorHostal->obtenerTipoConsumo();
      cout << "Consumos disponibles:\n";
      //imprimir tipoConsumos
      
      while(entrada == "si" && interfazControladorHostal->hayLugar()){
        string codigoConsumo;
        cout << "Ingrese el código del consumo: ";
        cin >> codigoConsumo;
        interfazControladorHostal->seleccionarTipoConsumo(codigoConsumo);
        
        cout << "Desea ingresar más consumos?: si/no\n";
        cin >> entrada;
      
      }
      
    }
    */
    cout << "Desea confirmar el alta?: ";
    cin >> entrada;
    if(entrada=="si"){
      interfazControladorHostal->confirmarAltaHabitacion(numero, capacidad, precio);
      cout<<"Habitación confirmada!";
    }
    
  }catch (std::invalid_argument &e){
    cout<< std::endl <<e.what() <<std::endl;
  }
}