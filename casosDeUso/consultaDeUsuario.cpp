#include "consultaDeUsuario.h"

using std::cout;
using std::cin;
using std::string;

void consultaDeUsuario(Fabrica* fabrica){
    IControladorUsuario* controladorUsuario = fabrica->getIControladorUsuario();
    map<string, DTUsuario*> usuarios = controladorUsuario->obtenerUsuarios();
    map<string, DTUsuario*>::iterator it;
    cout<< "Los usuarios registrados en el sistema son: "<<std::endl;
    int i = 1;
    for(it = usuarios.begin(); it!=usuarios.end(); ++it){
        cout << i<<") nombre: "<<it->second->getNombre()<<std::endl;
        cout <<"email: " <<it->second->getEmail() <<std::endl;
        cout <<std::endl;
        i++;
    }
    cout<<"Ingrese el email del usuario que desea seleccionar: ";
    string emailIngresado;
    cin>>emailIngresado;
    it = usuarios.begin();
    while(it!=usuarios.end() && it->first!=emailIngresado)
        ++it;
    if (it==usuarios.end())
        cout<<"El email ingresado es incorrecto";
    else{
        cout<<*it->second;
    }
    
    //libero la memoria de los DTUsuario creados
    it = usuarios.begin();
    map<string, DTUsuario*>::iterator anterior;
    while(it!=usuarios.end()){
        anterior = it;
        ++it;
        delete anterior->second;
    }



}