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
#include "SDL.h"


// Personaje::Personaje(): ObjetoConDuenio(), estado(QUIETO), orientacion(S), thrAccion(NULL) {
//   printf("Creando personaje...\n");
// }

Personaje::Personaje(
  unsigned int x, unsigned int y, unsigned int ancho, unsigned int alto, unsigned int velocidad
		     ) : ObjetoConDuenio(x,y,ancho,alto),
			 estado(QUIETO),
			 orientacion(S), 
			 thrAccion(NULL),
			 velocidad(velocidad) 
{}

void Personaje::caminar(unsigned int destX, unsigned int destY){
  if ( thrAccion ) SDL_KillThread(thrAccion);
  this->destX=destX-getAncho()/2;
  this->destY=destY-getAlto();
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

void Personaje::setPos(unsigned int x,unsigned int y){
  this->x=x-getAncho()/2;
  this->y=y;
  printf("setPos(): x=%d, y=%d\n",x,y);
 }

int Personaje::entCaminar(void* t){
  Personaje* pthis=(Personaje*)t;
  return pthis->_caminar();
}

int Personaje::_caminar(){
  //  Mapa& mapa = *Mapa::getInstance();
  unsigned int antMapaX, antMapaY;
  unsigned int mapaX, mapaY;
  this->estado=CAMINANDO;
  while 
    ( (x > destX+velocidad) || (x < destX-velocidad) 
      || (y > destY+velocidad) || (y < destY-velocidad) ) 
    {
    //   mapaX=destX/mapa.getLongCasilla();
    //   mapaY=destY/mapa.getLongCasilla();
    // //mapa(mapaX,mapaY)->ponerObjeto((ObjetoMapa*) this);
      
    //   antMapaX=destX/mapa.getLongCasilla();
    //   antMapaY=destY/mapa.getLongCasilla();
  
    // //mapa(antMapaX,antMapaY)->ponerObjeto(NULL);
      x+=destX>x?velocidad:-velocidad;
      y+=destY>y?velocidad:-velocidad;
      SDL_Delay(100);
    }
  this->estado=QUIETO;
  return 1;
}
