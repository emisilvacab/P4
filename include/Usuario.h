#ifndef Usuario_h
#define Usuario_h

#include <string.h>
#include <iostream>
#include <map>

using std::string;
using std::map;

class Reserva;

class Usuario{
  private:
    string nombre;
    string email;
    string password;
    map<string, Reserva*> reservas;
  public:
    Usuario();
    virtual ~Usuario();
    string getNombre();
    string getEmail();
    string getPassword();
    void setNombre(string nombreIngresado);
    void setEmail(string emailIngresado);
    void setPassword(string passwordIngresado);
};

#endif