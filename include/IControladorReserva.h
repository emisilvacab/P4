#ifndef IControladorReserva_h
#define IControladorReserva_h

#include "../datatypes/DTHostalCalificacion.h"
#include "../datatypes/DTHabitacion.h"
#include "../datatypes/DTHuesped.h"
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTEvaluacion.h"
#include "../datatypes/DTReserva.h"
#include <string>
#include <map>

using std::string;
using std::map;

class IControladorReserva{
  public:
    //Realizar Reserva
    virtual void confirmarReserva()=0;
    //Registrar Estadia
    virtual void seleccionarReserva(int codigo)=0;
    virtual void crearEstadia()=0;
    //Finalizar Estadia
    virtual void seleccionarEstadiaActiva(string email)=0;
    virtual void finalizarEstadia()=0;
    //Consulta Estadia
    virtual bool seleccionarEstadia(string emailIngresado, int codigoIngresado)=0;
    virtual DTReserva* obtenerReservaAsociada()=0;
    virtual DTEvaluacion obtenerEvaluacionAsociada()=0;
    virtual void ingresarCalificacion(string comentario,int  calificacion) = 0;
    //Baja de Reserva
    virtual void seleccionarReservaPorHostal(int codigo)=0;      virtual void confirmarBajadeReserva()=0;
};

#endif