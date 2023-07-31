#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "casosDeUso/altaDeHabitacion.h"
#include "casosDeUso/altaDeHostal.h"
#include "casosDeUso/altaDeUsuario.h"
#include "casosDeUso/asignarEmpleadoAHostal.h"
#include "casosDeUso/bajaDeReserva.h"
#include "casosDeUso/calificarEstadia.h"
#include "casosDeUso/cargarDatos.h"
#include "casosDeUso/comentarCalificacion.h"
#include "casosDeUso/consultaDeHostal.h"
#include "casosDeUso/consultaDeNotificaciones.h"
#include "casosDeUso/consultaDeUsuario.h"
#include "casosDeUso/consultaEstadia.h"
#include "casosDeUso/consultaReserva.h"
#include "casosDeUso/consultarTop3DeHostales.h"
#include "casosDeUso/eliminarSuscripcion.h"
#include "casosDeUso/finalizarEstadia.h"
#include "casosDeUso/modificarHoraDelSistema.h"
#include "casosDeUso/realizarReserva.h"
#include "casosDeUso/registrarEstadia.h"
#include "casosDeUso/suscribirseNotificaciones.h"

#include "include/Fabrica.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::string;

int main() {
  Fabrica *fabrica = new Fabrica();
  // IControladorUsuario* controladorUsuario =
  // fabrica->getIControladorUsuario(); //peligroso que el IControladorUsuario
  // se llame controladorUsuario siono?

  // lo mismo para los otros controladores
  // IControladorHostal* controladorHostal = fabrica->getIControladorHostal();
  // IControladorReserva* controladorReserva =
  // fabrica->getIControladorReserva(); IHoraDelSistema* horaDelSistema =
  // fabrica->getIHoraDelSistema();

  int entrada; // definicion de entrada como int
  do {
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout
        << "╔══════════════════════════════════════════════════════════════╗"
        << std::endl;
    std::cout
        << "║ 1.Alta de Usuario                                            ║"
        << std::endl;
    std::cout
        << "║ 2.Alta de Hostal                                             ║"
        << std::endl;
    std::cout
        << "║ 3.Alta de Habitación                                         ║"
        << std::endl;
    std::cout
        << "║ 4.Asignar empleado a hostal                                  ║"
        << std::endl;
    std::cout
        << "║ 5.Realizar Reserva                                           ║"
        << std::endl;
    std::cout
        << "║ 6.Consultar top 3 de hostales                                ║"
        << std::endl;
    std::cout
        << "║ 7.Registrar Estadía                                          ║"
        << std::endl;
    std::cout
        << "║ 8.Finalizar Estadía                                          ║"
        << std::endl;
    std::cout
        << "║ 9.Calificar Estadía                                          ║"
        << std::endl;
    std::cout
        << "║ 10.Comentar Calificación                                     ║"
        << std::endl;
    std::cout
        << "║ 11.Consulta de Usuario                                       ║"
        << std::endl;
    std::cout
        << "║ 12.Consulta de Hostal                                        ║"
        << std::endl;
    std::cout
        << "║ 13.Consulta de Reserva                                       ║"
        << std::endl;
    std::cout
        << "║ 14.Consulta de Estadía                                       ║"
        << std::endl;
    std::cout
        << "║ 15.Baja de reserva                                           ║"
        << std::endl;
    std::cout
        << "║ 16.Suscribirse a Notificaciones                              ║"
        << std::endl;
    std::cout
        << "║ 17.Consulta de Notificaciones                                ║"
        << std::endl;
    std::cout
        << "║ 18.Eliminar Suscripción                                      ║"
        << std::endl;
    std::cout
        << "║ 19.Modificar Fecha del Sistema                               ║"
        << std::endl;
    std::cout
        << "║ 20.Cargar datos predeterminados                              ║"
        << std::endl;
    std::cout
        << "║ 21.Salir                                                     ║"
        << std::endl;
    std::cout
        << "╚══════════════════════════════════════════════════════════════╝"
        << std::endl;
    std::cout << "Ingrese el número correspondiente a la operación deseada:  ";
    cin >> entrada;
    switch (entrada) {
    case 1: // Alta de Usuario
      altaDeUsuario(fabrica);
      break;

    case 2: // Alta de Hostal
      altaDeHostal(fabrica);
      break;

    case 3: // Alta de Habitacion
      altaDeHabitacion(fabrica);
      break;

    case 4:
      asignarEmpleadoAHostal(fabrica);
      break;

    case 5: // RealizarReserva
      realizarReserva(fabrica);
      break;

    case 6: // Consultar top 3 de hostales
      consultarTop3DeHostales(fabrica);
      break;

    case 7: // Registrar Estadia
      registrarEstadia(fabrica);
      break;

    case 8: // Finalizar Estadia
      finalizarEstadia(fabrica);
      break;

    case 9: // Calificar Estadia
      calificarEstadia(fabrica);
      break;

    case 10: // Comentar Calificacion
      comentarCalificacion(fabrica);
      break;

    case 11:
      consultaDeUsuario(fabrica);
      break;

    case 12: // Consulta de Hostal
      consultaDeHostal(fabrica);
      break;

    case 13: // Consulta de Reserva
      consultaReserva(fabrica);
      break;

    case 14: // Consulta de Estadia
      consultaEstadia(fabrica);
      break;

    case 15: // Baja de Reserva
      bajaDeReserva(fabrica);
      break;

    case 16: // Suscribirse a Notificaciones
      suscribirseNotificaciones(fabrica);
      break;

    case 17: // Consulta de Notificaciones
      consultaDeNotificaciones(fabrica);
      break;

    case 18: // Eliminar Suscripcion
      eliminarSuscripcion(fabrica);
      break;

    case 19: // Modificiar hora del Sistema
      modificarHoraDelSistema(fabrica);
      break;

    case 20:
      cargarDatos(fabrica);
      break;
    }
  } while (0 < entrada && entrada < 21);

  delete fabrica;
  return 0;
}