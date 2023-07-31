#ifndef Fabrica_h
#define Fabrica_h

#include "IControladorUsuario.h"
#include "ControladorUsuario.h"
#include "IControladorHostal.h"
#include "ControladorHostal.h"
#include "IControladorReserva.h"
#include "ControladorReserva.h"
#include "IHoraDelSistema.h"
#include "HoraDelSistema.h"

class Fabrica{
public:
  IControladorUsuario* getIControladorUsuario();
  IControladorHostal* getIControladorHostal();
  IControladorReserva* getIControladorReserva();
  IHoraDelSistema* getIHoraDelSistema();
};

#endif
