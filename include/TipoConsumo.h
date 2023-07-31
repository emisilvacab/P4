#ifndef TipoConsumo_h
#define TipoConsumo_h

#include <string.h>
#include <iostream>

using std::string;

class TipoConsumo {
  private:
    string codigo, nombre;
    float precio;

  public:
    TipoConsumo(string codigoIngresado, string nombreIngresado, float precioIngresado);

    string getCodigo();
    string getNombre();
    float getPrecio();
    void setCodigo(string codigoIngresado);
    void setNombre(string nombreIngresado);
    void setPrecio(float precioIngresado);
  
};

#endif