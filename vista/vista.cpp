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
#include "vista.h"


int Vista(void* v){

  P_Vista* param=(P_Vista*)v;
  SDL_Surface* screen=param->screen;
  SDL_Jugador* jug=param->jug;
  SDL_Rect pos;
  SDL_Vista* terreno;
  SDL_Vista* o;
  ObjetoMapa* objetoMapa;
  Mapa& mapa=*Mapa::getInstance();
  int y,x;

  // Carga de tiles auxiliares
  SDL_Surface* tileSeleccion=cargarTile("seleccion.png");
  //

  for (;;){
    for (y=0 ; y<mapa.getAlto(); y++){
      for (x=0 ; x<mapa.getAncho(); x++){
  	pos.x=x*32;
  	pos.y=y*32;
	terreno=dynamic_cast<SDL_Vista*>(mapa(x,y));
	if( terreno!=NULL ){
	  SDL_BlitSurface(terreno->getSurface(),NULL,screen,&pos);
	  objetoMapa=mapa(x,y)->getContenido();
	  if ( objetoMapa != NULL ){
	    pos.x=objetoMapa->getX()-(objetoMapa->getAncho()/2);
	    pos.y=objetoMapa->getY()-(objetoMapa->getAlto());
	    o=dynamic_cast<SDL_Vista*>(objetoMapa);
	    if( o != NULL ) {
	      SDL_BlitSurface(o->getSurface(),NULL,screen,&pos);
	    }
	  }
	}
      }
    }
    objetoMapa=jug->getSeleccion();
    if ( objetoMapa ) {
      pos.x=objetoMapa->getX()-8;
      pos.y=objetoMapa->getY()-objetoMapa->getAlto()-10;
      SDL_BlitSurface(tileSeleccion,NULL,screen,&pos);
    }
    SDL_Flip(screen);
    SDL_Delay(FREC_PINTADO);
  }
}

SDL_Surface* cargarTile(const char* tileFile) {
  char aux[200];
  SDL_Surface* tile;
  sprintf(aux,"%stiles/%s",Data_Dir(),tileFile);
  tile=IMG_Load(aux);
  if ( tile == NULL ) 
    printf("%s\n",IMG_GetError());
  return tile;
}

// SDL_Surface** Cargar_Tiles(const char* tmpl, int n){
//   SDL_Surface** s;
//   int i;
//   char aux[100];
//   s=(SDL_Surface**)malloc(sizeof(SDL_Surface*)*n);

//   for (i=0; i<n;i++) {
//     sprintf(aux,tmpl,n);
//     s[i]=IMG_Load(aux);
//     if ( s[i] == NULL ) {
//       printf("%s\n",IMG_GetError());
//     }
//   }
//   return s;
// }
