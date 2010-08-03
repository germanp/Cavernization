/**
 * @file   dibujar.cpp
 * @author Germán Podestá
 * @date   Sun Jun 13 12:03:40 2010
 * 
 * @brief  Este archivo tiene las rutinas para dibujar el juego en la pantalla
 * 
 * @section TODO
 *  - Mejorar la carga de tiles para que se vea y funcione con cualquier path.
 */


#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "mapa.h"
#include "objetomapa.h"
#include "vista.h"
#include "sdl_vista.h"

int Vista(void* v){
  SDL_Surface* screen=(SDL_Surface*)v;
  SDL_Rect pos;
  Mapa& mapa=*Mapa::getInstance();
  int y,x;
  while (1){
    for (y=0 ; y<mapa.getAlto(); y++){
      for (x=0 ; x<mapa.getAncho(); x++){
  	pos.x=x*32;
  	pos.y=y*32;
	SDL_Vista* terreno=dynamic_cast<SDL_Vista*>(mapa(x,y));
	if( terreno!=NULL ){
	  SDL_BlitSurface(terreno->getSurface(),NULL,screen,&pos);
	  ObjetoMapa* objetoMapa=mapa(x,y)->getContenido();
	  if ( objetoMapa != NULL ){
	    pos.x=objetoMapa->getX();
	    pos.y=objetoMapa->getY();
	    SDL_Vista* o=dynamic_cast<SDL_Vista*>(objetoMapa);
	    if( o != NULL ) SDL_BlitSurface(o->getSurface(),NULL,screen,&pos);
	  }
	}
      }
    }
    SDL_Flip(screen);
    SDL_Delay(FREC_PINTADO);
  }
}

SDL_Surface** Cargar_Tiles(const char* tmpl, int n){
  SDL_Surface** s;
  int i;
  char aux[100];
  s=(SDL_Surface**)malloc(sizeof(SDL_Surface*)*n);

  for (i=0; i<n;i++) {
    sprintf(aux,tmpl,n);
    s[i]=IMG_Load(aux);
    if ( s[i] == NULL ) {
      printf("%s\n",IMG_GetError());
    }
  }
  return s;
}
