#include "altaDeHostal.h"
using std::string;
using std::cout;
using std::cin;

void altaDeHostal(Fabrica* fabrica){
  try{
    IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();

    string nombre, direccion, telefono;
    cout << "Ingrese el nombre del hostal: ";
    cin.ignore( 1, '\n' ); //saca el \n que se ingresa al seleccionar el caso
    getline(cin,nombre);
    cout << "Ingrese la dirección del hostal: ";
    //cin.ignore( 0, '\n' );
    getline(cin,direccion);
    cout << "Ingrese el teléfono del hostal: ";
    //cin.ignore( 0, '\n' );
    getline(cin,telefono);

    DTHostal data = DTHostal(nombre,direccion,telefono);
    interfazControladorHostal->ingresarDatosHostal(data);

    string palabra;
    cout<< "Desea confirmar el alta?: si/no: ";
    cin >> palabra;
    if(palabra=="si"){
      interfazControladorHostal->confirmarAltaHostal();
      cout<<"Hostal registrado!\n";
    
    }else if(palabra=="no"){
      cout<<"Confirmación cancelada!\n";
    
    }else{
      cout<<"Operación no válida!\n";
    }
  
  }catch (std::invalid_argument &e){
    cout<< std::endl <<e.what() <<std::endl;
  }

}