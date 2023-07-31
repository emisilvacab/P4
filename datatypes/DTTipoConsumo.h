#ifndef DTTipoConsumo_h
#define DTTipoConsumo_h

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>

using std::string;

class DTTipoConsumo{
  private:
    string nombre, codigo;
    float precio;

  public:
    DTTipoConsumo(string nombreIngresado, string codigoIngresado, float precioIngresado);
    DTTipoConsumo();
    string getNombre();
    string getCodigo();
    float getPrecio();
};

#endif