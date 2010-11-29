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
#include "SDL.h"


// Personaje::Personaje(): ObjetoConDuenio(), estado(QUIETO), orientacion(S), thrAccion(NULL) {
//   printf("Creando personaje...\n");
// }

Personaje::Personaje(
  unsigned int x, unsigned int y, unsigned int ancho, unsigned int alto, unsigned int velocidad, Terreno* casillla
		     ) : ObjetoConDuenio(x,y,ancho,alto),
			 estado(QUIETO),
			 orientacion(S), 
			 thrAccion(NULL),
			 velocidad(velocidad) 
{
  this->casilla=casilla;
}

void Personaje::caminar(unsigned int destX, unsigned int destY){
  if ( thrAccion ) SDL_KillThread(thrAccion);
  this->destX=destX;
  this->destY=destY;
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

bool Personaje::desplazar(){
  unsigned int mapaX, mapaY;
  Mapa& mapa = *Mapa::getInstance();
  this->estado=CAMINANDO;
  while 
    ( (x > destX+velocidad) || (x < destX-velocidad) 
      || (y > destY+velocidad) || (y < destY-velocidad) ) 
    {
      x+=destX>x?velocidad:-velocidad;
      y+=destY>y?velocidad:-velocidad;

      mapaX=x/mapa.getLongCasilla();
      mapaY=y/mapa.getLongCasilla();

      Terreno* t=mapa(mapaX,mapaY);
      if ( t != casilla ) {
	if ( !cambiarCasilla(t) ) {
	  return 0;
	}
      }
      SDL_Delay(100);
    }
  this->estado=QUIETO;
  return 1;
}

int Personaje::_caminar(){
  desplazar();
  return 1;
}

void Personaje::setCasilla(Terreno* c){
  this->casilla=c;
}

bool Personaje::cambiarCasilla(Terreno* nvaCasilla){
    ///////////
    // MUTEX //
    ///////////
  printf("Casilla: %d\n",casilla);
  printf("nvaCasilla: %d\n",nvaCasilla);
  if ( nvaCasilla->ponerObjeto(this) ) {
      casilla->quitarObjeto();
      casilla=nvaCasilla;
      return 1;
    } else 
      return 0;
  }
