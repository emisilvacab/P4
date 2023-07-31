#ifndef DTUsuario_h
#define DTUsuario_h

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>

using std::string;
using namespace std;

class DTUsuario{
  protected:
    string nombre, email, password;

  public:
    //DTUsuario();
    virtual ~DTUsuario();
    string getNombre();
    string getEmail();
    string getPassword();
    void setNombre(string nombreIngresado);
    void setEmail(string emailIngresado);
    void setPassword(string passowrdIngresado);
    virtual void printUsuario(ostream &o)=0;
};
ostream &operator << (ostream &output, DTUsuario &usuario);

#endif