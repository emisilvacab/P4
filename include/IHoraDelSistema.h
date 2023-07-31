#ifndef IHoraDelSistema_h
#define IHoraDelSistema_h

#include "../datatypes/DTFecha.h"

class IHoraDelSistema {
  public:
    virtual DTFecha getFecha() = 0;
    virtual void setFecha(DTFecha fechaIngresada) = 0;
};

#endif