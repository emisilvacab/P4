#ifndef IControladorUsuario_h
#define IControladorUsuario_h

#include "../datatypes/DTUsuario.h"
#include "../datatypes/DTHuesped.h"
#include "../datatypes/DTEmpleado.h"
#include "../datatypes/DTReserva.h"
#include "../datatypes/DTEstadia.h"
#include "../datatypes/DTEvaluacion.h"
#include "Empleado.h"
#include "Usuario.h"

#include <list>
#include <map>
#include <vector>

class DTEmpleado; //fwrd?

using std::list;
using std::map;
using std::vector;

class IControladorUsuario{
  public:
    virtual void recordarTipoDeUsuarioRegistrando(bool tipoUsuarioRecordadoIngresado)=0;
    // virtual void seleccionarUsuario(string emailIngresado) =0;
    virtual bool ingresarHuesped(DTHuesped* datosUsuarioRecordadoIngresado)=0;
    virtual bool ingresarEmpleado(DTEmpleado* datosUsuarioRecordadoIngresado)=0;
    virtual bool ingresarEmail(string emailIngresado)=0;
    virtual void confirmarUsuario()=0;
    virtual void cancelarUsuario()=0;
    virtual map<string, DTEmpleado> obtenerEmpleadosNoAsignados() =0;
    virtual void seleccionarEmpleado(string emailIngresado, TipoCargo cargo)=0;
    virtual void confrimarAsignarEmpleadoHostal() =0;
    virtual list<DTReserva*> obtenerReservasNoCanceladas(string emailIngresado)=0;
    virtual void setUsuarioRecordado(Usuario* usuarioIngresado)=0;
    virtual vector<string> obtenerHuespedes()=0;
    virtual void seleccionarHuesped(string emailIngresado)=0;
    virtual void liberarHuespedesRecordados()=0;
    virtual map<string, DTUsuario*> obtenerUsuarios()=0;
    virtual DTHuesped obtenerHuesped(string email)=0;
    virtual void marcarHostalEmpleado(string email)=0;
    virtual vector<DTEstadia> obtenerEstadiasFinalizada(string email) = 0;
    virtual map<string, DTEmpleado> obtenerEmpleados() = 0;
    //virtual Empleado* obtenerEmpleado(string emailIngresado)=0;
    virtual void seleccionarSuscriptor(string emailIngresado)=0;
    virtual void suscribirEmpleado(string email) = 0;
    virtual void desuscribirEmpleado(string email) = 0;
    virtual bool seleccionarSiEstaSuscrito(string email) = 0;
    virtual vector<DTEvaluacion> devolverNotificaciones() = 0;
};

#endif