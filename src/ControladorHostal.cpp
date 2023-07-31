#include "../include/ControladorHostal.h"
#include <algorithm>

using std::pair;
using std::cout;

struct PromedioNombre{
  float promedio;
  string nombre;
};// para obtenerTop3

bool ComparePromedioNombre(PromedioNombre a, PromedioNombre b) {
  return (a.promedio > b.promedio);
}// para obtenerTop3

ControladorHostal * ControladorHostal::instance = NULL;

ControladorHostal::ControladorHostal(){} //Creadora

ControladorHostal * ControladorHostal::getInstance() {
  if (instance == NULL)
    instance = new ControladorHostal();
  return instance;
}

void ControladorHostal::setHostalRecordado(Hostal* hostal){
  this->hostalRecordado = hostal;
}

Hostal* ControladorHostal::getHostalRecordado(){
  return this->hostalRecordado;
}

void ControladorHostal::setCheckInRecordado(DTFecha checkInIngresado){
  this->checkInRecordado = checkInIngresado; 
}

void ControladorHostal::setCheckOutRecordado(DTFecha checkOutIngresado){
  this->checkOutRecordado = checkOutIngresado;
}

DTFecha ControladorHostal::getCheckInRecordado(){
  return this->checkInRecordado;
}

DTFecha ControladorHostal::getCheckOutRecordado(){
  return this->checkOutRecordado;
}


void ControladorHostal::setDatosHostalRecordado(DTHostal data){
  this->datosHostalRecordado = data;
}

void ControladorHostal::setDatosHabitacionRecordado(DTHabitacion data){
  this->datosHabitacionRecordado = data;
}

DTHostal ControladorHostal::getDatosHostalRecordado(){
  return this->datosHostalRecordado;
}

DTHabitacion ControladorHostal::getDatosHabitacionRecordado(){
  return this->datosHabitacionRecordado;
}

bool ControladorHostal::existsHostal(string nombreIngresado){
  return this->hostales.find(this->datosHostalRecordado.getNombre()) != this->hostales.end();
}

void ControladorHostal::addHostal(Hostal* hostal){
  this->hostales.insert({hostal->getNombre(),hostal});
}

/*
void ControladorHostal::addTipoConsumo(TipoConsumo* tipoConsumo){
  this->tipoConsumoRegistrados.insert({tipoConsumo->getCodigo(),tipoConsumo});
}
*/

/*
TipoConsumo* ControladorHostal::createTipoConsumo(DTTipoConsumo data){
  TipoConsumo* tipoConsumo = new TipoConsumo(data.getCodigo(),data.getNombre(),data.getPrecio());
  return tipoConsumo;
}
*/

/*
void ControladorHostal::addTipoConsumoRecordado(TipoConsumo* tipoConsumo){
  this->tipoConsumoRecordados.insert({tipoConsumo->getCodigo(),tipoConsumo});
}
*/

/*
void ControladorHostal::limpiarTipoConsumoRecordados(){
  this->tipoConsumoRecordados.clear();
}    
*/


DTHostal ControladorHostal::getDatos(Hostal* hostal){ //getDatos para hostal
  DTHostal hostalDT = DTHostal(hostal->getNombre(),hostal->getDireccion(),hostal->getTelefono());
  return hostalDT;
}

//Alta de Hostal

void ControladorHostal::ingresarDatosHostal(DTHostal data){
  this->setDatosHostalRecordado(data);
}

void ControladorHostal::confirmarAltaHostal(){
  DTHostal data = this->getDatosHostalRecordado();
  /*
  bool yaRegistrado = this->existsHostal(data.getNombre());
  
  if(!yaRegistrado){
    Hostal* hostal = this->createHostal(data);
    this->addHostal(hostal);
  }
  */
  Hostal* hostal = new Hostal(data.getNombre(), data.getDireccion(), data.getTelefono());
  
  this->hostales.insert({data.getNombre(),hostal});
  
}

//Alta de Habitacion

map<string, DTHostal> ControladorHostal::obtenerHostales(){
  map<string,DTHostal> hostalesDT;

  map<string, Hostal*>::iterator it;
  for(it = this->hostales.begin(); it != this->hostales.end();it++){
    DTHostal hostalDT = this->getDatos(it->second);
    hostalesDT.insert({it->first,hostalDT});
  }
  
  return hostalesDT;
}

void ControladorHostal::seleccionarHostal(string nombre){
  try{
    map<string,Hostal*>::iterator it = this->hostales.begin();
    while((it != this->hostales.end()) && (it->second->getNombre()!=nombre)){
      ++it;
    }
  
    if(it!=this->hostales.end()){
      this->setHostalRecordado(it->second);   
    }else{
      this->setHostalRecordado(NULL);
      throw std::invalid_argument("Hostal no registrado en el sistema.");
    }
  }
    catch(std::invalid_argument &a){
      std::cout<<std::endl <<a.what() << std::endl;
    }
}

/*
map<string, DTTipoConsumo> ControladorHostal::obtenerTipoConsumo(){
  map<string,DTTipoConsumo> tipoConsumosDT;

  map<string, TipoConsumo*>::iterator it;
  for(it = this->tipoConsumoRegistrados.begin(); it != this->tipoConsumoRegistrados.end();it++){
    DTTipoConsumo tipoConsumoDT = this->getDatos(it->second);
    tipoConsumosDT.insert({it->first,tipoConsumoDT});
  }
  
  return tipoConsumosDT;
}
*/

/*
void ControladorHostal::seleccionarTipoConsumo(string codigo){
  map<string,TipoConsumo*>::iterator it = this->tipoConsumoRegistrados.begin();
  while((it != this->tipoConsumoRegistrados.end()) && (it->second->getCodigo()!=codigo)){
    it++;
  }

  if(it!=this->tipoConsumoRegistrados.end()){
    this->addTipoConsumoRecordado(it->second);   
  }
  
}
*/

void ControladorHostal::confirmarAltaHabitacion(int numero, int capacidad, float precio){
  Hostal* hostal = this->getHostalRecordado();
  Habitacion* habitacion = new Habitacion(numero, capacidad, precio, hostal);
}

bool ControladorHostal::hayLugar(){
  return this->tipoConsumoRecordados.size() < 10;
}


/*
//Alta de Tipo Consumo

void ControladorHostal::ingresarTipoConsumo(DTTipoConsumo tipoConsumo){
  this->datosTipoConsumoRecordado = tipoConsumo;
}

void ControladorHostal::ConfirmarAltaTipoConsumo(){
  TipoConsumo* nuevoTipoConsumo = this->createTipoConsumo(this->getDatosTipoConsumoRecordado());
  
  this->addTipoConsumo(nuevoTipoConsumo);
}    
*/


//Consultar top 3 de Hostales

vector<string> ControladorHostal::obtenerTop(){
  map<string, Hostal*> hostales = this->hostales;
  map<string, Hostal*>::iterator i;
  vector<PromedioNombre> aux;
  vector<string> res;
  for (i = hostales.begin(); i != hostales.end(); i++){
    float promedio = i->second->getPromedio();
    aux.push_back({promedio, i->second->getNombre()});
  }
  sort(aux.begin(), aux.end(), ComparePromedioNombre);
  for(int n = 0; (n < aux.size()) && (res.size() < 3) ; n++){
    res.push_back(aux[n].nombre);
  }
  //aux.~map();
  return res;
}

vector<DTEvaluacion> ControladorHostal::obtenerEvaluacionesHostal(string nombreIngresado){
  map<string, Hostal*>::iterator it = this->hostales.begin();
  while(it != this->hostales.end() && it->first != nombreIngresado)
    it++;
  return it->second->getDTEvaluaciones();
}


//Auxiliares de Realizar Reserva
map<string, Hostal*> ControladorHostal::getHostales(){
  return this->hostales;
}

void ControladorHostal::setHabitacionRecordada(Habitacion* habitacion){
  this->habitacionRecordada = habitacion;
}

Habitacion* ControladorHostal::getHabitacionRecordada(){
  return this->habitacionRecordada;
}


//Realizar Reserva
map<string, DTHostalCalificacion> ControladorHostal::obtenerHostalesCalificacion(){
  map<string, Hostal*> hostales = this->getHostales();
  map<string, Hostal*>::iterator i;
  map<string, DTHostalCalificacion> hostalesCalificacion;

  for(i = hostales.begin(); i != hostales.end(); i++){
    DTHostalCalificacion nuevo = DTHostalCalificacion(i->second->getNombre(),i->second->getDireccion(),i->second->getTelefono(), i->second->getPromedio()); 
    hostalesCalificacion.insert(pair<string, DTHostalCalificacion>(nuevo.getNombre(), nuevo));
  }
  return hostalesCalificacion;
}

map<int, DTHabitacion> ControladorHostal::obtenerHabitacionesDisponibles(DTFecha checkIn, DTFecha checkOut){
  Hostal* hostal = this->getHostalRecordado(); 
  map<int, Habitacion*> habitaciones = hostal->getHabitaciones();
  map<int, DTHabitacion> habitacionesDisponibles;

  map<int, Habitacion*>::iterator it;
  for(it = habitaciones.begin(); it != habitaciones.end(); it++){
    if(it->second->isDisponible(checkIn,checkOut)){
      DTHabitacion habNueva = DTHabitacion(it->second->getNumero(), it->second->getCapacidad(),it->second->getPrecio());
      habitacionesDisponibles.insert({habNueva.getNumero(), habNueva});
      // son punteros a Habitacion el map
    }
  }
  this->setCheckInRecordado(checkIn);
  this->setCheckOutRecordado(checkOut);
  return habitacionesDisponibles;
}

void ControladorHostal::seleccionarHabitacion(int num){
  Hostal* hostal = this->getHostalRecordado();
  this->setHabitacionRecordada(hostal->getHabitacion(num));
};

//Consulta de Reserva

vector<DTReserva*> ControladorHostal::obtenerReservas(){
  Hostal* hostal = this->getHostalRecordado();
  return hostal->getDatosReservas();
}

//Consulta de Hostal

DTHostalCalificacion ControladorHostal::obtenerHostalCalificacion(){
  Hostal* hostal = this->getHostalRecordado();
  vector<Evaluacion*> evaluaciones = hostal->getEvaluaciones();
  
  int sum = 0;
  
  for(Evaluacion* ev : evaluaciones){
    sum = sum + ev->getCalificacion();
  }
  
  float promedio = 0;
  
  if(evaluaciones.size() != 0)
    float promedio = sum/evaluaciones.size();

  
  DTHostalCalificacion hostalDT = DTHostalCalificacion(hostal->getNombre(), hostal->getDireccion(), hostal->getTelefono(), promedio);

  return hostalDT;
}


vector<DTHabitacionEvaluacion> ControladorHostal::obtenerHabitacionEvaluacion(){
  vector<DTHabitacionEvaluacion> habitacionesDT;
  
  Hostal* hostal = this->getHostalRecordado();
  map<int, Habitacion*> habitaciones = hostal->getHabitaciones();
  map<int, Habitacion*>::iterator i;
  
  for(i = habitaciones.begin();i != habitaciones.end(); i++){

    vector<DTEvaluacion> evaluaciones;
  
    map<int,Reserva*> reservas = i->second->getReservas();
    map<int,Reserva*>::iterator j;
    
    for(j = reservas.begin(); j != reservas.end(); j++){

   
    vector<Estadia*> estadias = j->second->getEstadiasFinalizadas(); //la funcion nueva, te devuelve solo las finalizadas
    	
    	for(Estadia* k : estadias){

    	  Evaluacion* evaluacion = k->getEvaluacion();
        DTEvaluacion evaluacionDT = DTEvaluacion(evaluacion->getCalificacion(), evaluacion->getComentario(), evaluacion->getRespuesta(), evaluacion->getFecha());
    	  evaluaciones.push_back(evaluacionDT);
    	
    	}	
 

      
    	
    }
    
    DTHabitacionEvaluacion habitacionDT = DTHabitacionEvaluacion(i->second->getNumero(), i->second->getCapacidad(), i->second->getPrecio(), evaluaciones);
    
    habitacionesDT.push_back(habitacionDT);
  
  }
  
  return habitacionesDT;

}


vector<DTEstadia> ControladorHostal::obtenerEstadias(){
  Hostal* host = this->hostalRecordado;
  map<int, Reserva*> reservas = host->getReservas();
  map<int, Reserva*>::iterator itRes;
  vector<DTEstadia> res;
  for(itRes = reservas.begin(); itRes != reservas.end(); itRes++){
    vector<Estadia*> estadias = itRes->second->getEstadias();
    for(int itEst = 0; itEst < estadias.size(); itEst++){
      res.push_back(estadias[itEst]->getDatos());
    }
  }
  return res;
}

DTHostal ControladorHostal::obtenerHostal(string nombre){
  return this->hostales.find(nombre)->second->getDatos();
}

vector<DTEvaluacion> ControladorHostal::obtenerEvaluacionesSinRespuesta(){
  Hostal* hostal = this->hostalRecordado;
  vector<DTEvaluacion> evaluaciones = hostal->getDTEvaluaciones();
  vector<DTEvaluacion> res;
  
  for(int i =0; i < evaluaciones.size(); i++){
    if (evaluaciones[i].getRespuesta() == "")
      res.push_back(evaluaciones[i]);
  }
  /*
  for(DTEvaluacion ev: evaluaciones){
    if (ev.getRespuesta() == "")
      res.push_back(ev);
  }
*/
  
  return res;
}

void ControladorHostal::seleccionarEvaluacionSR(DTEvaluacion evaluacion){
  Hostal* hostal = this->hostalRecordado;
  vector<Evaluacion*> evaluaciones = hostal->getEvaluaciones();
  for(int i = 0; i < evaluaciones.size(); i++){
    if(evaluaciones[i]->getCalificacion() == evaluacion.getCalificacion() && evaluaciones[i]->getComentario() == evaluacion.getComentario() && evaluaciones[i]->getFecha() == evaluacion.getFecha() && evaluaciones[i]->getRespuesta() == evaluacion.getRespuesta())
      this->evaluacionRecordada = evaluaciones[i];
  }
}

void ControladorHostal::comentarCalificacion(string respuesta){
  Evaluacion* evaluacion = this->evaluacionRecordada;
  evaluacion->setRespuesta(respuesta);
  ControladorUsuario* controladorUsuario = ControladorUsuario::getInstance();
  Usuario* usuario = controladorUsuario->getUsuarioRecordado();
  Empleado* empleado = dynamic_cast<Empleado*>(usuario);
  if (empleado)
    evaluacion->setEmpleado(empleado);
}
