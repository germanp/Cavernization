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

Personaje::Personaje(): ObjetoConDuenio(), estado(QUIETO), orientacion(S), thrAccion(NULL) {
  printf("Creando personaje...\n");
}

Personaje::Personaje(int x,int y) : ObjetoConDuenio(x,y), estado(QUIETO), orientacion(S), thrAccion(NULL) {}

void Personaje::caminar(int destX, int destY){
  this->destX=destX;
  this->destY=destY;
  this->estado=CAMINANDO;
  printf("Estado: %d\n",this->estado);
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

  int mapaX=destX/mapa.getLongCasilla();
  int mapaY=destY/mapa.getLongCasilla();
  this->x=destX;
  this->y=destY;
  printf("destX: %d - destY: %d\n",destX,destY);
  return 1;
}
