#ifndef DTFecha_h
#define DTFecha_h

#include <iostream>
using std::ostream;

class DTFecha{
  private:
    int hora;
    int dia;
    int mes;
    int anio;
  public:
    DTFecha();
    DTFecha(int hora,int dia, int mes, int anio);
    int getHora();
    int getDia();
    int getMes();
    int getAnio();
    void setHora(int hora);
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    bool operator==(DTFecha fecha);
    bool operator!=(DTFecha fecha);
    bool operator<(DTFecha f);
    friend ostream &operator << (ostream &output, DTFecha &fecha);
};

#endif