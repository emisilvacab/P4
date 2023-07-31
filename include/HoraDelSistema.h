#ifndef HoraDelSistema_h
#define HoraDelSistema_h

#include "IHoraDelSistema.h"
#include <stdio.h>

class HoraDelSistema : public IHoraDelSistema {
  private:
    static HoraDelSistema * instance;
    HoraDelSistema();
    DTFecha fecha;
  public:
    static HoraDelSistema * getInstance();
    DTFecha getFecha();
    void setFecha(DTFecha fechaIngresada);
};

#endif