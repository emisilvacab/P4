#ifndef DTEmpleado_h
#define DTEmpleado_h

#include "DTIObserver.h"
#include "DTUsuario.h"
#include "../utils.h"
#include "../include/Suscripciones.h"

class DTEmpleado : public DTUsuario, public DTIObserver{
  private:
    TipoCargo cargo;
    string hostal;
  protected:
      virtual void printUsuario(ostream &o);

  public:
    DTEmpleado();
    DTEmpleado(string nombreIngresado, string emailIngresado, string passwordIngresado, TipoCargo cargoIngresado);
    TipoCargo getCargo();
    void setTipoCargo(TipoCargo tipoCargoIngresado);
    void setHostal(string hostalIngresado);
    string getHostal();
    DTIObserver getSuscriptorRecordado();
};

#endif