#ifndef ControladorReserva_h
#define ControladorReserva_h

#include "IControladorReserva.h"
#include "ControladorUsuario.h"
#include "HoraDelSistema.h"
#include "Reserva.h"

class ControladorReserva: public IControladorReserva{
  private:
    static ControladorReserva* instance;
    Reserva* reservaRecordada;
    string nombreRecordado, emailRecordado;
    DTFecha checkInRecordado, checkOutRecordado;
    int numeroDeHabitacionRecordado;
    int codigoGenerado;
    Estadia* estadiaRecordada;
    ControladorReserva();
  public:
    //Getters
    static ControladorReserva* getInstance();
    Reserva* getReservaRecordada();
    string getNombreRecordado(); 
    string getEmailRecordado();
    DTFecha getCheckInRecordado();
    DTFecha getCheckOutRecordado();
    int getNumeroDeHabitacionRecordado();
    Estadia* getEstadiaRecordada();
    //Setters
    void setReservaRecordada(Reserva* reserva);
    void setNombreRecordado(string nombre); 
    void setEmailRecordado(string email);
    void setCheckInRecordado(DTFecha checkIn);
    void setCheckOutRecordado(DTFecha checkOut);
    void setNumeroDeHabitacionRecordado(int numeroDeHabitacion);
    void setEstadiaRecordada(Estadia* estadiaIngresado);
    //Realizar Reserva
    void confirmarReserva();
    //Registrar estadia
    void seleccionarReserva(int codigo);
    void crearEstadia();
    //Finalizar estadia
    void seleccionarEstadiaActiva(string email);
    void finalizarEstadia();
    //Consulta Estadia
    bool seleccionarEstadia(string emailIngresado, int codigoIngresado); //devuelve true si tiene una evaluacion
    void ingresarCalificacion(string comentario,int  calificacion);
    DTReserva* obtenerReservaAsociada();
    DTEvaluacion obtenerEvaluacionAsociada();
    //Baja de Reserva
    void seleccionarReservaPorHostal(int codigo);  
    void confirmarBajadeReserva();
};

#endif