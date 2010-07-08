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
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "mapa.h"
#include "vista.h"
//
#include "sdl_vista.h"
#include "sdl_tile.h"
//

int Vista(void* v){
  SDL_Surface* screen=(SDL_Surface*)v;
  SDL_Rect pos;
  Mapa& mapa=*Mapa::getInstance();
  int y,x;
  while (1){
    for (y=0 ; y<mapa.getAlto(); y++){
      for (x=0 ; x<mapa.getAncho(); x++){
  	pos.x=x*64;
  	pos.y=(y-1)*64;
  	SDL_Vista* sdlVista=dynamic_cast<SDL_Vista*>(mapa(x,y));
	if ( sdlVista )	SDL_BlitSurface(sdlVista->getSurface(),NULL,screen,&pos)
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

void Liberar_Tiles(SDL_Surface** s){
  int i, length=sizeof(s)/sizeof(SDL_Surface*);
  for (i=0; i<length;i++) {
    SDL_FreeSurface(s[i]);
    free(s[i]);
  }
}

Terreno** Cargar_Mapa(){
  int m[100]= {0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,2,0,0,0,0,
	       0,0,1,0,0,0,0,1,0,0,
	       2,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,1,0,0,0,2,0,
	       0,0,0,0,0,0,0,0,0,0,
	       0,2,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,1,0,0,
	       0,0,1,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0};
  const int ANCHO=10, ALTO=10;
  int i, length=ANCHO*ALTO;
  Terreno** _mapa=new Terreno*[length];
  for (i=0;i<length;i++){
    switch ( m[i] ){
    case 0:
      _mapa[i]=new SDL_Tile<SDL_Pasto>();
      break;
    case 1:
      _mapa[i]=new SDL_Tile<SDL_PastoPiedra>();
      break;
    case 2:
      _mapa[i]=new SDL_Tile<SDL_PastoPiedra2>();
      break;
    }
  }
  return _mapa;
}
