#ifndef Estadia_h
#define Estadia_h

#include <vector>
#include "../datatypes/DTFecha.h"
#include "../datatypes/DTEstadia.h"
#include "Consumo.h"
#include "Reserva.h"
#include "Huesped.h"

using std::vector;

class Evaluacion;

class Estadia{
  private:
    DTFecha checkIn;
    DTFecha checkOut;
    bool promo;
    float totalConsumido;
    Evaluacion* evaluacion;
    Reserva* reserva;
    Huesped* huesped;
    vector<Consumo*> consumos;
    bool estaActiva;
  public:
    Estadia(DTFecha checkInIngresado, bool promoIngresado, Huesped* huespedIngresado, Reserva* reservaIngresado);
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    bool getPromo();
    float getTotalConsumido();
    Evaluacion* getEvaluacion();
    vector<Consumo*> getConsumos();
    Reserva* getReserva();
    DTEstadia getDatos();
    bool getEstaActiva();
    Huesped* getHuesped();
    void setHuesped(Huesped* huespedIngresado);
    void setReserva(Reserva* reservaIngresado);
    void setCheckIn(DTFecha checkInIngresado);
    void setCheckOut(DTFecha checkOutIngresado);
    void setPromo(bool promoIngresado);
    void setTotalConsumido(float totalConsumidoIngresado);
    void setEvaluacion(Evaluacion* evaluacionIngresado);
    void setEstaActiva(bool activa);
    void destruirEvaluaciones();
    //agregar consumo
};

#endif