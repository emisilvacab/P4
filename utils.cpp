#include "utils.h"


TipoCargo obtenerCargo(string cargoIngresado){
  try{
      TipoCargo cargo;
      if (cargoIngresado == "Administracion" || cargoIngresado == "administracion")
          cargo = Administracion;
      else{
        if (cargoIngresado == "Limpieza" || cargoIngresado == "limpieza")
          cargo = Limpieza;
        else{
          if (cargoIngresado == "Recepcion" || cargoIngresado == "recepcion")
            cargo = Recepcion;
          else{
            if (cargoIngresado == "Infraestructura" || cargoIngresado == "infraestructura")
              cargo = Infraestructura;
            else
              throw std::invalid_argument("Cargo inválido");
          }
        }
      }
      return cargo;
    }
    catch(std::invalid_argument &a){
      std::cout << std::endl << a.what() << std::endl;
    }
}

string cargoAString(TipoCargo cargoIngresado){
  try{
    switch (cargoIngresado)
    {
    case Administracion:
      return "Administracion";
      break;
    case Limpieza:
      return "Limpieza";
      break;
    case Recepcion:
      return "Recepcion";
      break;
    case Infraestructura:
      return "Infraestructura";
      break;
    
    default:
      throw std::invalid_argument("Cargo invalido");
      break;
    }
  }
  catch(std::invalid_argument &a){
    std::cout<< std::endl <<a.what()<<std::endl;
  }
}

istream& operator>> (istream& in, TipoCargo& cargo){
  string entrada;
  in >> entrada;
  
  if(entrada == "Administracion" || entrada == "administracion"){
    cargo = Administracion;
    
  }else if(entrada == "Limpieza" || entrada == "limpieza"){
    cargo = Limpieza;
  
  }else if(entrada == "Recepcion" || entrada == "recepcion"){
    cargo = Recepcion;
  
  }else if(entrada == "Infraestructura" || entrada == "infraestructura"){
    cargo = Infraestructura;
  
  }
  
  return in;
}