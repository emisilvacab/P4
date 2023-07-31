#include "../include/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instance = NULL;

ControladorUsuario::ControladorUsuario(){}

ControladorUsuario* ControladorUsuario::getInstance(){
  if(instance == NULL)
    instance = new ControladorUsuario();
  return instance;
}

DTUsuario* ControladorUsuario::getDatosRecordados() {
  return this->datosUsuarioRecordado;
}

void ControladorUsuario::setDatosRecordados(DTUsuario* datosUsuarioRecordadoIngresado) {
  this->datosUsuarioRecordado = datosUsuarioRecordadoIngresado;
}

void ControladorUsuario::recordarTipoDeUsuarioRegistrando(bool tipoUsuarioRecordadoIngresado){
  this->setTipoDeUsuarioARegistrar(tipoUsuarioRecordadoIngresado);
}

bool ControladorUsuario::ingresarHuesped(DTHuesped* datosHuespedRecordadoIngresado){
  this->setDatosRecordados(datosHuespedRecordadoIngresado);
  string email = datosHuespedRecordadoIngresado->getEmail();
  bool res = ((this->empleados.find(email) != this->empleados.end())) || ((this->huespedes.find(email) != this->huespedes.end()));
  return res;
}

bool ControladorUsuario::ingresarEmpleado(DTEmpleado* datosEmpleadoRecordadoIngresado){
  this->setDatosRecordados(datosEmpleadoRecordadoIngresado);
  return this->empleados.find(datosEmpleadoRecordadoIngresado->getEmail()) != this->empleados.end() || (this->huespedes.find(datosEmpleadoRecordadoIngresado->getEmail()) != this->huespedes.end());
}

bool ControladorUsuario::ingresarEmail(string emailIngresado){
  this->getDatosRecordados()->setEmail(emailIngresado);
  return  (this->empleados.find(emailIngresado) != this->empleados.end()) || (this->huespedes.find(emailIngresado) != this->huespedes.end());
  
}

void ControladorUsuario::confirmarUsuario(){
  bool esHuesped = this->getTipoDeUsuarioARegistrar();
  DTUsuario* data = this->getDatosRecordados();
  if (esHuesped) {
    DTHuesped* nuevo = dynamic_cast<DTHuesped*>(data);
    if (nuevo){
      Huesped* huesped = new Huesped(nuevo->getNombre(), nuevo->getEmail(), nuevo->getPassword(), nuevo->getEsFinger()); 
      //delete nuevo; //no se si es necesario pero por las dudas
      this->huespedes.insert({data->getEmail(), huesped});
    }
  }
  else {
    DTEmpleado* nuevo = dynamic_cast<DTEmpleado*>(data);
    if (nuevo){
      Empleado* empleado = new Empleado(nuevo->getNombre(), nuevo->getEmail(), nuevo->getPassword(), nuevo->getCargo()); 
      //delete nuevo; //no sabemos si pide memoria el dynamic_cast
      this->empleados.insert({data->getEmail(), empleado});
    }
  }
  //delete data;
}

void ControladorUsuario::cancelarUsuario(){}

void ControladorUsuario::setTipoDeUsuarioARegistrar(bool tipoUsuarioRecordadoIngresado) {
  this->tipoUsuarioRecordado = tipoUsuarioRecordadoIngresado;
}

bool ControladorUsuario::getTipoDeUsuarioARegistrar(){
  return this->tipoUsuarioRecordado;
}

void ControladorUsuario::setUsuarioRecordado(Usuario* usuarioIngresado){
   this->usuarioRecordado = usuarioIngresado;
}

list<DTReserva*> ControladorUsuario::obtenerReservasNoCanceladas(string emailIngresado) {
  map<string, Huesped*>::iterator it;
  it = this->huespedes.find(emailIngresado);
  list<DTReserva*> res = it->second->obtenerReservasNoCanceladas();
  this->usuarioRecordado = it->second;
  return res;
}

map<string, DTEmpleado> ControladorUsuario::obtenerEmpleadosNoAsignados(){
  map<string, DTEmpleado> empleadosSinAsignar;
  map<string, Empleado*>::iterator it;
  map<string, Empleado*> empleados = this->empleados;
  for(it = empleados.begin(); it != empleados.end(); it++){
    if (it->second->empleadoNoAsignado())
      empleadosSinAsignar.insert({it->first, DTEmpleado(it->second->getNombre(), it->second->getEmail(), it->second->getPassword(), it->second->getCargo())});
    
  }
  return empleadosSinAsignar;
}

void ControladorUsuario::seleccionarEmpleado(string emailIngresado, TipoCargo cargo){
  try{
    map<string, Empleado*>::iterator it;
    it = this->empleados.find(emailIngresado);
    if (it == this->empleados.end())
      throw std::invalid_argument("No existe empleado con el email ingresado.");
    this->usuarioRecordado = it->second;
    this->cargoRecordado = cargo;
  }catch(std::invalid_argument &e){
    cout<<std::endl << e.what() << std::endl;
  }
}

    
TipoCargo ControladorUsuario::getCargoRecordado(){
  return this->cargoRecordado;
}

void ControladorUsuario::confrimarAsignarEmpleadoHostal(){
  ControladorHostal* controladorHostal = ControladorHostal::getInstance();
  Hostal* hos = controladorHostal->getHostalRecordado();
  Usuario* usuario = this->getUsuarioRecordado();
  Empleado* empleado = dynamic_cast<Empleado*>(usuario);
  if (empleado){
    hos->addEmpleado(empleado);
    TipoCargo cargo = this->getCargoRecordado();
    empleado->linkHostal(hos, cargo);
  }
  
  
}

Usuario* ControladorUsuario::getUsuarioRecordado() {
  return this->usuarioRecordado;
}

map<string, Huesped*> ControladorUsuario::getHuespedes(){
  return this->huespedes;
}

vector<string> ControladorUsuario::obtenerHuespedes(){
  vector<string> res;
  map<string, Huesped*> aux = this->huespedes;
  map<string, Huesped*>::iterator it;
  for(it = aux.begin(); it != aux.end(); it++){
    res.push_back(it->first);
  }
  return res;
}

void ControladorUsuario::seleccionarHuesped(string emailIngresado){
  try{
    map<string, Huesped*> huespedes = this->huespedes;
    map<string, Huesped*>::iterator it = huespedes.begin();
    while(it != huespedes.end() && it->first != emailIngresado)
      it++;
    if (it != huespedes.end())
      this->huespedesRecordados.insert({emailIngresado, it->second}); 
    else
      throw std::invalid_argument("No existe huésped con el email ingresado!");
  }catch(std::invalid_argument &e){
    cout<<std::endl << e.what() << std::endl;
  }
    
}

map<string, Huesped*> ControladorUsuario::getHuespedesRecordados(){
  return this->huespedesRecordados;
}

void ControladorUsuario::liberarHuespedesRecordados(){
  this->huespedesRecordados.clear();
}

map<string, DTUsuario*> ControladorUsuario::obtenerUsuarios(){
  map<string, DTUsuario*> resu;
  map<string, Empleado*> empleados = this->empleados;
  map<string, Empleado*>::iterator i;
  for(i = empleados.begin(); i!=empleados.end(); ++i){
    DTEmpleado* nuevoEmpleado = new DTEmpleado(i->second->getNombre(), i->second->getEmail(), i->second->getPassword(), i->second->getCargo());
    if (i->second->getHostal() == NULL)
      nuevoEmpleado->setHostal("");
    else
      nuevoEmpleado->setHostal(i->second->getHostal()->getNombre());
    resu.insert({i->first, nuevoEmpleado});
  }
  map<string, Huesped*> huespedes = this->huespedes;
  map<string, Huesped*>::iterator it;
  for (it = huespedes.begin(); it!=huespedes.end(); ++it){
    DTHuesped* nuevoHuesped = new DTHuesped(it->second->getNombre(), it->second->getEmail(), it->second->getPassword(), it->second->getEsFinger());
    resu.insert({it->first, nuevoHuesped});

  }
  return resu;
}

Huesped* ControladorUsuario::getHuesped(string email){
  return this->huespedes.find(email)->second;
}

Empleado* ControladorUsuario::getEmpleado(string email){
  return this->empleados.find(email)->second;
}

DTHuesped ControladorUsuario::obtenerHuesped(string email){
  return this->huespedes.find(email)->second->getDatos();
}

void ControladorUsuario::marcarHostalEmpleado(string email){
  map<string, Empleado*>::iterator it;
  map<string, Empleado*> empleados = this->empleados;
  it = empleados.begin();
  while(it != empleados.end() && it->first != email)
    it++;
  
  this->usuarioRecordado = it->second;
  Hostal* hostal = it->second->getHostal();
  ControladorHostal* controladorHostal = ControladorHostal::getInstance();
  controladorHostal->setHostalRecordado(hostal);
}

vector<DTEstadia> ControladorUsuario::obtenerEstadiasFinalizada(string email) {
  map<string, Huesped*>::iterator it;
  it = this->huespedes.find(email);
  Huesped* huesped = it->second;
  vector<DTEstadia> res;
  for (int i = 0; i < (huesped->getEstadias()).size(); i++) {
    if (!(huesped->getEstadias()[i]->getEstaActiva())) {
      res.push_back(huesped->getEstadias()[i]->getDatos());
    }
  }
  return res;
}


map<string, DTEmpleado> ControladorUsuario::obtenerEmpleados(){
  map<string, DTEmpleado> resu;
  map<string, Empleado*> empleados = this->empleados;
  map<string, Empleado*>::iterator i;
  for(i = empleados.begin(); i!=empleados.end(); ++i){
    DTEmpleado nuevoEmpleado = DTEmpleado(i->second->getNombre(), i->second->getEmail(), i->second->getPassword(), i->second->getCargo());
    if (i->second->getHostal() == NULL)
      nuevoEmpleado.setHostal("");
    else
      nuevoEmpleado.setHostal(i->second->getHostal()->getNombre());
    resu.insert({i->first, nuevoEmpleado});
  }
  return resu;
}

void ControladorUsuario::seleccionarSuscriptor(string emailIngresado){
  try{
    map<string, Empleado*>::iterator it;
    it = this->empleados.find(emailIngresado);
    if (it == this->empleados.end())
      throw std::invalid_argument("No existe empleado con el email ingresado.");
    this->usuarioRecordado = it->second;
  }catch(std::invalid_argument &e){
    cout<<std::endl << e.what() << std::endl;
  }
}

void ControladorUsuario::suscribirEmpleado(string email) {
  Empleado* nuevoSuscriptor = this->getEmpleado(email);
  Suscripciones* instance = Suscripciones::getInstance();
  instance->suscribir(nuevoSuscriptor);
}

void ControladorUsuario::desuscribirEmpleado(string email) {
  Empleado* nuevoSuscriptor = this->getEmpleado(email);
  Suscripciones* instance = Suscripciones::getInstance();
  instance->eliminar(nuevoSuscriptor);
}

bool ControladorUsuario::seleccionarSiEstaSuscrito(string email) {
  Empleado* empleado = this->getEmpleado(email);
  Suscripciones* suscripcionesSingle = Suscripciones::getInstance();
  vector<IObserver*> colSuscriptos = suscripcionesSingle->getSuscriptos();
  int i = 0;
  while ((i < colSuscriptos.size()) && (colSuscriptos[i] != empleado))
    i++;
  if (i < colSuscriptos.size()) {
    this->setUsuarioRecordado(empleado);
    return true;
  } else
    return false;
}

vector<DTEvaluacion> ControladorUsuario::devolverNotificaciones() {
  Usuario* notificado = this->getUsuarioRecordado();
  Empleado* empNotificado = dynamic_cast<Empleado*>(notificado);
  vector<Notificacion*> notificacionesEmp = empNotificado->getNotificaciones();
  vector<DTEvaluacion> ansNotificaciones;
  int i;
  Notificacion* notificacion;
  while (!notificacionesEmp.empty()) {
    i = notificacionesEmp.size() - 1; //para el ultimo elemento
    notificacion = notificacionesEmp[i];
    if (notificacion->getEvaluacion() != NULL)
      ansNotificaciones.push_back(notificacion->getEvaluacion()->getDatos());
    notificacionesEmp.pop_back();
    notificacion->setCantNotificados(notificacion->getCantNotificados() - 1);
    if (notificacion->getCantNotificados() == 0)
      delete notificacion;
  }
  empNotificado->limpiarNotificaciones(); //sacas las notificaciones vistas de empleado
  return ansNotificaciones;
}