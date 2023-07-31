#ifndef IObserver_h
#define IObserver_h

class Notificacion;

class IObserver {
  public:
    IObserver();
    virtual ~IObserver();
    virtual void notificar(Notificacion * notificacionIngresada) = 0;
};

#endif