#include "cargarDatos.h"

void cargarDatos(Fabrica* fabrica){
  IControladorUsuario* interfazControladorUsuario = fabrica->getIControladorUsuario();

  //Huespedes
  DTHuesped* data = new DTHuesped("Sofia", "sofia@mail.com", "123", true);
  interfazControladorUsuario->recordarTipoDeUsuarioRegistrando(true);
  interfazControladorUsuario->ingresarHuesped(data);
  interfazControladorUsuario->confirmarUsuario();
  delete data;
  data = new DTHuesped("Frodo", "frodo@mail.com", "123", true);
  interfazControladorUsuario->ingresarHuesped(data);
  interfazControladorUsuario->confirmarUsuario();
  delete data;
  data = new DTHuesped("Sam", "sam@mail.com", "123", false);
  interfazControladorUsuario->ingresarHuesped(data);
  interfazControladorUsuario->confirmarUsuario();
  delete data;
  data = new DTHuesped("Merry", "merry@mail.com", "123", false);
  interfazControladorUsuario->ingresarHuesped(data);
  interfazControladorUsuario->confirmarUsuario();
  delete data;
  data = new DTHuesped("Pippin", "pippin@mail.com", "123", false);
  interfazControladorUsuario->ingresarHuesped(data);
  interfazControladorUsuario->confirmarUsuario();
  delete data;
  data = new DTHuesped("Seba", "seba@mail.com", "123", true);
  interfazControladorUsuario->ingresarHuesped(data);
  interfazControladorUsuario->confirmarUsuario();
  delete data;

  //Empleados
  DTEmpleado* empleado = new DTEmpleado("Emilia", "emilia@mail.com", "123", Recepcion);
  interfazControladorUsuario->recordarTipoDeUsuarioRegistrando(false);
  interfazControladorUsuario->ingresarEmpleado(empleado);
  interfazControladorUsuario->confirmarUsuario();
  delete empleado;
  empleado = new DTEmpleado("Leonardo", "leo@mail.com", "123", Recepcion);
  interfazControladorUsuario->ingresarEmpleado(empleado);
  interfazControladorUsuario->confirmarUsuario();
  delete empleado;
  empleado = new DTEmpleado("Alina", "alina@mail.com", "123", Administracion);
  interfazControladorUsuario->ingresarEmpleado(empleado);
  interfazControladorUsuario->confirmarUsuario();
  delete empleado;
  empleado = new DTEmpleado("Barliman", "barli@mail.com", "123", Recepcion);
  interfazControladorUsuario->ingresarEmpleado(empleado);
  interfazControladorUsuario->confirmarUsuario();
  delete empleado;

  //Hostales
  IControladorHostal* interfazControladorHostal = fabrica->getIControladorHostal();
  
  DTHostal hostal = DTHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");
  interfazControladorHostal->ingresarDatosHostal(hostal);
  interfazControladorHostal->confirmarAltaHostal();
  hostal = DTHostal("Mochileros", "Rambla Costanera 333, rocha", "42579512");
  interfazControladorHostal->ingresarDatosHostal(hostal);
  interfazControladorHostal->confirmarAltaHostal();
  hostal = DTHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");
  interfazControladorHostal->ingresarDatosHostal(hostal);
  interfazControladorHostal->confirmarAltaHostal();
  hostal = DTHostal("Altos de Fing", "Av del Toro 1424", "099892992");
  interfazControladorHostal->ingresarDatosHostal(hostal);
  interfazControladorHostal->confirmarAltaHostal();
  hostal = DTHostal("Caverna Lujosa", "Amaya 2515", "233233235");
  interfazControladorHostal->ingresarDatosHostal(hostal);
  interfazControladorHostal->confirmarAltaHostal();

  //Habitaciones
  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorHostal->confirmarAltaHabitacion(1, 2, 40);
  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorHostal->confirmarAltaHabitacion(2, 7, 10);
  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorHostal->confirmarAltaHabitacion(3, 3, 30);
  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorHostal->confirmarAltaHabitacion(4, 12, 5);
  interfazControladorHostal->seleccionarHostal("Caverna Lujosa");
  interfazControladorHostal->confirmarAltaHabitacion(1, 2, 3);
  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  interfazControladorHostal->confirmarAltaHabitacion(1, 5, 9);



  //asignacion de empleados a hostales
  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorUsuario->seleccionarEmpleado("emilia@mail.com", Recepcion);
  interfazControladorUsuario->confrimarAsignarEmpleadoHostal();
  interfazControladorHostal->seleccionarHostal("Mochileros");
  interfazControladorUsuario->seleccionarEmpleado("leo@mail.com", Recepcion);
  interfazControladorUsuario->confrimarAsignarEmpleadoHostal();
  interfazControladorHostal->seleccionarHostal("Mochileros");
  interfazControladorUsuario->seleccionarEmpleado("alina@mail.com", Administracion);
  interfazControladorUsuario->confrimarAsignarEmpleadoHostal();
  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  interfazControladorUsuario->seleccionarEmpleado("barli@mail.com", Recepcion);
  interfazControladorUsuario->confrimarAsignarEmpleadoHostal();
 
  //reservas
  IControladorReserva* interfazControladorReserva = fabrica->getIControladorReserva();
  
  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorHostal->seleccionarHabitacion(1);
  interfazControladorUsuario->seleccionarHuesped("sofia@mail.com");
  DTFecha checkIn = DTFecha(14, 1, 5, 2022);
  DTFecha checkOut = DTFecha(10, 10, 5, 2022);
  interfazControladorHostal->setCheckInRecordado(checkIn);
  interfazControladorHostal->setCheckOutRecordado(checkOut);
  interfazControladorReserva->confirmarReserva();
  interfazControladorUsuario->liberarHuespedesRecordados();

  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  interfazControladorHostal->seleccionarHabitacion(1);
  interfazControladorUsuario->seleccionarHuesped("frodo@mail.com");
  interfazControladorUsuario->seleccionarHuesped("sam@mail.com");
  interfazControladorUsuario->seleccionarHuesped("merry@mail.com");
  interfazControladorUsuario->seleccionarHuesped("pippin@mail.com");
  checkIn = DTFecha(20, 4, 1, 2001);
  checkOut = DTFecha(2, 5, 1, 2001);
  interfazControladorHostal->setCheckInRecordado(checkIn);
  interfazControladorHostal->setCheckOutRecordado(checkOut);
  interfazControladorReserva->confirmarReserva();
  interfazControladorUsuario->liberarHuespedesRecordados();

  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorHostal->seleccionarHabitacion(3);
  interfazControladorUsuario->seleccionarHuesped("sofia@mail.com");
  checkIn = DTFecha(14, 7, 6, 2022);
  checkOut = DTFecha(11, 30, 6, 2022);
  interfazControladorHostal->setCheckInRecordado(checkIn);
  interfazControladorHostal->setCheckOutRecordado(checkOut);
  interfazControladorReserva->confirmarReserva();
  interfazControladorUsuario->liberarHuespedesRecordados();

  interfazControladorHostal->seleccionarHostal("Caverna Lujosa");
  interfazControladorHostal->seleccionarHabitacion(1);
  interfazControladorUsuario->seleccionarHuesped("seba@mail.com");
  checkIn = DTFecha(14, 10, 6, 2022);
  checkOut = DTFecha(11, 30, 6, 2022);
  interfazControladorHostal->setCheckInRecordado(checkIn);
  interfazControladorHostal->setCheckOutRecordado(checkOut);
  interfazControladorReserva->confirmarReserva();
  interfazControladorUsuario->liberarHuespedesRecordados();

//REGISTRAR ESTADIA 
  IHoraDelSistema* interfazHoraDelSistema = fabrica->getIHoraDelSistema();

  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazHoraDelSistema->setFecha(DTFecha(18, 1, 5, 2022));
  list<DTReserva*> reservasNoCanceladas = interfazControladorUsuario->obtenerReservasNoCanceladas("sofia@mail.com");
  //delete esta lista
  interfazControladorReserva->seleccionarReserva(1);
  interfazControladorReserva->crearEstadia();  

  for(DTReserva* res : reservasNoCanceladas){
     delete res;
  }
  reservasNoCanceladas.clear();

  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  interfazHoraDelSistema->setFecha(DTFecha(21, 4, 1, 2001));
  reservasNoCanceladas = interfazControladorUsuario->obtenerReservasNoCanceladas("frodo@mail.com");
  interfazControladorReserva->seleccionarReserva(2);
  interfazControladorReserva->crearEstadia();

  for(DTReserva* res : reservasNoCanceladas){
     delete res;
  }
  reservasNoCanceladas.clear();
  
  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  reservasNoCanceladas = interfazControladorUsuario->obtenerReservasNoCanceladas("sam@mail.com");
  interfazControladorReserva->seleccionarReserva(2);
  interfazControladorReserva->crearEstadia();  

  for(DTReserva* res : reservasNoCanceladas){
     delete res;
  }
  reservasNoCanceladas.clear();
  
  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  reservasNoCanceladas = interfazControladorUsuario->obtenerReservasNoCanceladas("merry@mail.com");
  interfazControladorReserva->seleccionarReserva(2);
  interfazControladorReserva->crearEstadia();  

  for(DTReserva* res : reservasNoCanceladas){
     delete res;
  }
  reservasNoCanceladas.clear();
  
  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  reservasNoCanceladas = interfazControladorUsuario->obtenerReservasNoCanceladas("pippin@mail.com");
  interfazControladorReserva->seleccionarReserva(2);
  interfazControladorReserva->crearEstadia();

  for(DTReserva* res : reservasNoCanceladas){
     delete res;
  }
  reservasNoCanceladas.clear();
  
  interfazControladorHostal->seleccionarHostal("Caverna Lujosa");
  interfazHoraDelSistema->setFecha(DTFecha(18, 7, 6, 2022));
  reservasNoCanceladas = interfazControladorUsuario->obtenerReservasNoCanceladas("seba@mail.com");
  interfazControladorReserva->seleccionarReserva(4);
  interfazControladorReserva->crearEstadia();  

  for(DTReserva* res : reservasNoCanceladas){
     delete res;
  }
  reservasNoCanceladas.clear();
  

//FINALIZAR ESTADIA
  interfazHoraDelSistema->setFecha(DTFecha(9, 10, 5, 2022));
  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorReserva->seleccionarEstadiaActiva("sofia@mail.com");
  interfazControladorReserva->finalizarEstadia();
  interfazHoraDelSistema->setFecha(DTFecha(2, 5, 1, 2001));
  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  interfazControladorReserva->seleccionarEstadiaActiva("frodo@mail.com");
  interfazControladorReserva->finalizarEstadia();
  interfazHoraDelSistema->setFecha(DTFecha(22, 15, 6, 2022));
  interfazControladorHostal->seleccionarHostal("Caverna Lujosa");
  interfazControladorReserva->seleccionarEstadiaActiva("seba@mail.com");
  interfazControladorReserva->finalizarEstadia();

//CALIFICAR ESTADIA
  interfazHoraDelSistema->setFecha(DTFecha(18, 11, 5, 2022));
  interfazControladorHostal->seleccionarHostal("La posada del finger");
  interfazControladorReserva->seleccionarEstadia("sofia@mail.com", 1);
  interfazControladorReserva->ingresarCalificacion("Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.", 3);
  
  interfazHoraDelSistema->setFecha(DTFecha(3, 5, 1, 2001));
  interfazControladorHostal->seleccionarHostal("El Pony Pisador");
  interfazControladorReserva->seleccionarEstadia("frodo@mail.com", 2);
  interfazControladorReserva->ingresarCalificacion("Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.", 2);
  
  interfazHoraDelSistema->setFecha(DTFecha(23, 15, 6, 2011));
  interfazControladorHostal->seleccionarHostal("Caverna Lujosa");
  interfazControladorReserva->seleccionarEstadia("seba@mail.com", 4);
  interfazControladorReserva->ingresarCalificacion("Había pulgas en la habitación. Que lugar más mamarracho!!", 1);

  //COMENTAR CALIFICACION
  interfazControladorUsuario->marcarHostalEmpleado("barli@mail.com");
  vector<DTEvaluacion> evaluaciones = interfazControladorHostal->obtenerEvaluacionesSinRespuesta();
  interfazControladorHostal->seleccionarEvaluacionSR(evaluaciones[0]);
  interfazControladorHostal->comentarCalificacion("Desapareció y se fue sin pagar. 6/1/2001 15hs");

  cout<<"Datos ingresados!"<<endl;

}