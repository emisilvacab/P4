#include "../include/Fabrica.h"

using std::cin;
using std::cout;
using std::getline;

void altaDeUsuario(Fabrica* fabrica){
  try{
    IControladorUsuario* controladorUsuario = fabrica->getIControladorUsuario();
    cout <<"El usuario será un huesped? ";
    string palabra;
    bool esHuesped;
    cin>>palabra;
    esHuesped = (palabra == "si");
    controladorUsuario->recordarTipoDeUsuarioRegistrando(esHuesped);
    cout << "Ingrese el nombre: ";  
    string nombre, email, contrasena;
    cin.ignore(1,'\n');
    getline(cin,nombre);
    cout << "Ingrese el email: ";
    getline(cin,email);
    cout << "Ingrese la contraseña: ";
    getline(cin,contrasena);
    bool esFinger;
    TipoCargo cargo;
    if (esHuesped){
      cout<< "Ingrese si es finger: ";
      cin>>palabra;
      esFinger = (palabra == "si");
    }
    else{
      cout<<"Ingrese el cargo: ";
      //string cargoIngresado; 
      cin >> cargo;
      //cargo = obtenerCargo(cargoIngresado);
    }
    bool yaRegistrado, probarDeNuevo = true;;
    if (esHuesped) {
      DTHuesped* data = new DTHuesped(nombre, email, contrasena, esFinger);
      yaRegistrado = controladorUsuario->ingresarHuesped(data);
    }
    else {
      DTEmpleado* data = new DTEmpleado(nombre, email, contrasena, cargo);
      yaRegistrado = controladorUsuario->ingresarEmpleado(data);
    }
//    bool yaRegistrado;
/*    if (esHuesped)
      yaRegistrado = controladorUsuario->ingresarHuesped(data);//hay q hacer cast
    else
      yaRegistrado = controladorUsuario->ingresarEmpleado(data);
*/
    while ((yaRegistrado) && (probarDeNuevo)){
        cout <<"El email ingresado ya esta registrado, desea ingresar un nuevo email? ";
        cin>>palabra;
        probarDeNuevo = (palabra == "si");
        if (probarDeNuevo){
            cout << "Ingrese el nuevo email: ";
            cin >> email;
            yaRegistrado = controladorUsuario->ingresarEmail(email);
          }
    }
    if (yaRegistrado)
      throw std::invalid_argument("El email ingresado ya esta asociado a un usuario.");
    //bool confirmar;
    cout << "Desea confirmar el alta? ";
    cin >> palabra;
    if (palabra=="si"){
      controladorUsuario->confirmarUsuario(); //delete data
      cout << "Alta confirmada!";
    }
    else{
      controladorUsuario->cancelarUsuario(); //delete data
      cout << "Alta cancelada!";
    }
  }
  catch (std::invalid_argument &e){
    cout<< std::endl <<e.what() <<std::endl;
  }
}