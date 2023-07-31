#ifndef ControladorHostal_h
#define ControladorHostal_h

#include "IControladorHostal.h"
#include "ControladorUsuario.h"

class ControladorHostal: public IControladorHostal{
  private: 
    static ControladorHostal * instance;
    ControladorHostal();
    DTHostal datosHostalRecordado;
    Hostal* hostalRecordado;
    Evaluacion* evaluacionRecordada;
    DTHabitacion datosHabitacionRecordado;
    Habitacion* habitacionRecordada;
    map<string, Hostal*> hostales;
    map<string, TipoConsumo*> tipoConsumoRegistrados;
    map<string, TipoConsumo*> tipoConsumoRecordados;
    DTFecha checkInRecordado;
    DTFecha checkOutRecordado;
  public:
    void setCheckInRecordado(DTFecha checkInIngresado);
    void setCheckOutRecordado(DTFecha checkOutIngresado);
    DTFecha getCheckInRecordado();
    DTFecha getCheckOutRecordado();
    static ControladorHostal * getInstance();
    map<string, Hostal*> getHostales();
    void setHostalRecordado(Hostal* hostal);
    Hostal* getHostalRecordado();
    void setDatosHostalRecordado(DTHostal data);
    void setDatosHabitacionRecordado(DTHabitacion data);
    DTHostal getDatosHostalRecordado();
    DTHabitacion getDatosHabitacionRecordado();
    DTHostal getDatos(Hostal* hostal);
    bool existsHostal(string nombreIngresado);
    void addHostal(Hostal* hostal);
    void agregarHabitacion(Habitacion* habitacion);
    //Alta de Hostal
    void ingresarDatosHostal(DTHostal data);
    void confirmarAltaHostal();
    //Alta de Habitacion
    map<string, DTHostal> obtenerHostales();
    void seleccionarHostal(string nombre);
    void confirmarAltaHabitacion(int numero, int capacidad, float precio);
    bool hayLugar();
    // Consultar top 3 de hostales  
    vector<string> obtenerTop();
    vector<DTEvaluacion> obtenerEvaluacionesHostal(string nombreIngresado);
    //Realizar Reserva
    map<string, DTHostalCalificacion> obtenerHostalesCalificacion();
    map<int, DTHabitacion> obtenerHabitacionesDisponibles(DTFecha checkIn, DTFecha checkOut);
    void seleccionarHabitacion(int num);
    //funciones auxiliares de Realizar Reserva
    void setHabitacionRecordada(Habitacion* habitacion);
    Habitacion* getHabitacionRecordada();
    //Consulta de Reserva
    vector<DTReserva*> obtenerReservas();
    //Consulta de Hostal
    DTHostalCalificacion obtenerHostalCalificacion();
    vector<DTHabitacionEvaluacion> obtenerHabitacionEvaluacion();
    vector<DTEstadia> obtenerEstadias();
    //Consulta Estadia
    DTHostal obtenerHostal(string nombre);
    //Comentar Calificacion
    vector<DTEvaluacion> obtenerEvaluacionesSinRespuesta();
    void seleccionarEvaluacionSR(DTEvaluacion evaluacion);
    void comentarCalificacion(string respuesta);
};

#endif