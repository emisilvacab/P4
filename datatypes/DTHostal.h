#ifndef DTHostal_h
#define DTHostal_h

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>

using std::string;
using std::ostream;

class DTHostal{
  private:
    string nombre, direccion, telefono;

  public:
    DTHostal(string nombreIngresado, string direccionIngresado, string telefonoIngresado);
    DTHostal();

    string getNombre();
    string getDireccion();
    string getTelefono();
    //virtual void printHostal(ostream &o) = 0;
    //imprime solo el nombre del hostal
    friend ostream &operator << (ostream &output, DTHostal &hostal); //solo imprime el nombre
};



#endif