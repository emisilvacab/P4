#include "DTFecha.h"
#include <string>
#include <iostream>
#include <stdio.h>

DTFecha::DTFecha(){
  this->hora = -1;
  this->dia = -1;
  this->mes = -1;  
  this->anio = -1;
}

DTFecha::DTFecha(int hora, int dia, int mes, int anio){
  this->hora = hora;
  this->dia = dia;
  this->mes = mes;  
  this->anio = anio;
}

int DTFecha::getHora(){
  return this->hora;
}

int DTFecha::getDia(){
  return this->dia;
}

int DTFecha::getMes(){
  return this->mes;
}

int DTFecha::getAnio(){
  return this->anio;
}

void DTFecha::setHora(int hora){
  this->hora = hora;
}

void DTFecha::setDia(int dia){
  this->dia = dia;
}

void DTFecha::setMes(int mes){
  this->mes = mes;
}

void DTFecha::setAnio(int anio){
  this->anio = anio;
}

bool DTFecha::operator==(DTFecha fecha){
  return ((this->hora == fecha.getHora()) && (this->dia == fecha.getDia()) && (this->mes == fecha.getMes()) && (this->anio == fecha.getAnio()));
}

bool DTFecha::operator!=(DTFecha fecha){
  return ((this->hora != fecha.getHora()) || (this->dia != fecha.getDia()) || (this->mes != fecha.getMes()) || (this->anio != fecha.getAnio()));
}

bool DTFecha::operator< (DTFecha f){
    return (
      (this->getAnio() < f.getAnio()) ||
      (this->getMes() < f.getMes() && this->getAnio() < f.getAnio()) ||
      (this->getDia() < f.getDia() && this->getMes() < f.getMes() && this->getAnio() < f.getAnio() || 
      (this->getHora() < f.getHora() && this->getDia() < f.getDia() && this->getMes() < f.getMes() && this->getAnio() < f.getAnio()))
  
    );
}

ostream &operator << (ostream &output, DTFecha &fecha){
  int anio = fecha.getAnio();
  if (anio > 1000)
    anio = anio %100;
  output << fecha.getDia() << "/" << fecha.getMes() << "/" << anio << "  " << fecha.getHora() <<"hs";
  return output;
}