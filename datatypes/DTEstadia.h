#ifndef DTEstadia_h
#define DTEstadia_h

#include <string>
#include "DTFecha.h"

using std::string;

class DTEstadia {
  private:
    string email;
    int codigo;
    DTFecha checkIn, checkOut;
    bool promo;
    float totalConsumo;
  public:
    DTEstadia(string emailIngresado, int codigoIngresado, DTFecha checkInIngresado, DTFecha checkOutIngresado, bool promoIngresado, float totalConsumoIngresado);
    string getEmail();
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    bool getPromo();
    float getTotalConsumo();
    friend ostream &operator << (ostream &output, DTEstadia &estadia);
};

#endif