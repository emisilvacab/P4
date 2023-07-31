#ifndef DTHuesped_h
#define DTHuesped_h

#include "DTUsuario.h"
#include "../utils.h"

class DTHuesped : public DTUsuario{
  private:
    bool esFinger;
  protected:
    virtual void printUsuario(ostream &o);
  public:
    DTHuesped();
    DTHuesped(string nombreIngresado, string emailIngresado, string passwordIngresado, bool esFingerIngresado);
    bool getEsFinger();
    void setEsFinger(bool esFingerIngresado);
};

#endif