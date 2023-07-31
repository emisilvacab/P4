#ifndef ControladorUsuario_h
#define ControladorUsuario_h

#include "Usuario.h"
#include "Empleado.h"
#include "Huesped.h"
#include "../datatypes/DTEmpleado.h"
#include "../datatypes/DTHuesped.h"
#include "../datatypes/DTReserva.h"
#include "IControladorUsuario.h"
#include "ControladorHostal.h"
#include <list>
#include <stdio.h>

using  std::list;

class ControladorUsuario: public IControladorUsuario{
  private:
    //vector<Empleado*> empleadosSuscriptos;
    TipoCargo cargoRecordado;
    static ControladorUsuario *instance;
    DTUsuario* datosUsuarioRecordado;
    Usuario* usuarioRecordado;
    map<string, Huesped*> huespedesRecordados;
    bool tipoUsuarioRecordado;
    map<string, Empleado*> empleados;
    map<string, Huesped*> huespedes;
    ControladorUsuario();
  public:
    static ControladorUsuario* getInstance();
    void recordarTipoDeUsuarioRegistrando(bool tipoUsuarioRecordadoIngresado);
    bool ingresarHuesped(DTHuesped* datosHuespedIngresado);
    bool ingresarEmpleado(DTEmpleado* datosEmpleadoIngresado);
    bool ingresarEmail(string emailIngresado);
    void confirmarUsuario();
    void cancelarUsuario();
    void setTipoDeUsuarioARegistrar(bool tipoUsuarioRecordadoIngresado);
    void setDatosRecordados (DTUsuario* datosUsuarioRecordadoIngresado);
    bool getTipoDeUsuarioARegistrar();
    DTUsuario* getDatosRecordados();
    void confrimarAsignarEmpleadoHostal();
    TipoCargo getCargoRecordado();
    map<string, Huesped*> getHuespedesRecordados();
    map<string, Huesped*> getHuespedes();
    Huesped* getHuesped(string email);
    Empleado* getEmpleado(string email);
    DTHuesped obtenerHuesped(string email);
    list<DTReserva*> obtenerReservasNoCanceladas(string emailIngresado);
    void setUsuarioRecordado(Usuario* usuarioIngresado);
    Usuario* getUsuarioRecordado();
    map<string, DTEmpleado> obtenerEmpleados();
    map<string, DTEmpleado> obtenerEmpleadosNoAsignados();
    void seleccionarEmpleado(string emailIngresado, TipoCargo cargo);
    map<string, DTUsuario*> obtenerUsuarios();
    vector<string> obtenerHuespedes();  
    void seleccionarHuesped(string emailIngresado);
    void liberarHuespedesRecordados();
    void marcarHostalEmpleado(string email);
    void seleccionarSuscriptor(string emailIngresado);
    //Calificar Estadia
    vector<DTEstadia> obtenerEstadiasFinalizada(string email);
    //vector<Empleado*> obtenerEmpleadosSuscriptos();
    void suscribirEmpleado(string email);
    void desuscribirEmpleado(string email);
    bool seleccionarSiEstaSuscrito(string email);
    vector<DTEvaluacion> devolverNotificaciones();
};

#endif