/**
 * @file   personaje.cpp
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:27:58 2010
 *
 * @brief <Implementa los metodos de la clase Personaje.>
 *
 * @section TODO
 *  <>
 */

#include "personaje.h"
#include "mapa.h"

Personaje::Personaje(): ObjetoConDuenio(), estado(QUIETO), orientacion(S), thrAccion(NULL) {}

Personaje::Personaje(int x,int y) : ObjetoConDuenio(x,y), estado(QUIETO), orientacion(S), thrAccion(NULL) {}

void Personaje::caminar(int x, int y){
  this->destX=x;
  this->destY=y;
  // this->estado=CAMINANDO;
  if ( thrAccion ) SDL_KillThread(thrAccion);
  this->thrAccion = SDL_CreateThread(Personaje::entCaminar,this);
}

void Personaje::atacar(Personaje p){
     
     
}

void Personaje::atacar(Edificio e){
     
     
}

void Personaje::rezar(Monumento m){
     
     
}

void Personaje::recibirGolpe(int danio){
     
     
}

void Personaje::morir(){
         
}

Personaje::~Personaje(){
  
}

int Personaje::entCaminar(void* t){
  Personaje* pthis=(Personaje*)t;
  return pthis->_caminar();
}

int Personaje::_caminar(){
  Mapa& mapa = *Mapa::getInstance();
  ObjetoMapa* o = mapa(x/mapa.getLongCasilla(),y/mapa.getLongCasilla())->getContenido();
  // NO FUNCIONA BIEN, REVISAR
  x=destX-16;
  y=destY-16;
  mapa(x/mapa.getLongCasilla(),y/mapa.getLongCasilla())->ponerObjeto(o);
  printf("Ya caminé.\n");
  return 1;
}
