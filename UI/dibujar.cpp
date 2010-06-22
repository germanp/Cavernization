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
#include <mapa.h>
#include "dibujar.h"
#include "terreno.h"


int thr_Dibujar(void* v){
  SDL_Surface* s=(SDL_Surface*)v;
  Dibujar(s);
  return 0;
}

inline void Dibujar(SDL_Surface* screen){
  Mapa Map=*Mapa::getInstance();  
  SDL_Surface** tiles=Cargar_Tiles();
  SDL_Rect pos;
  int i,j,t;
  while (1){
    for (i=0 ; i<Map.getAlto(); i++){
      for (j=0 ; j<Map.getAncho(); j++){
  	t=i*Map.getAlto()+j;
  	pos.x=j*64;
  	pos.y=(i-1)*64;
  	SDL_BlitSurface(tiles[Map[t]->getTipo()],NULL,screen,&pos);
      }
    }
    SDL_Flip(screen);
    SDL_Delay(FREC_PINTADO);
  }
}

SDL_Surface** Cargar_Tiles(){
  ///////////
  // TILES //
  ///////////
  const char* paths[]={
    "UI/tiles/pasto0.png",
    "UI/tiles/pasto1.png",
    "UI/tiles/pasto2.png"
  };

  SDL_Surface** s;
  int i, length=sizeof(paths)/sizeof(char*);

  s=(SDL_Surface**)malloc(sizeof(SDL_Surface*)*length);

  for (i=0; i<length;i++) {
    s[i]=IMG_Load(paths[i]);
    if ( s[i] == NULL ) {
      printf("Error: No se pudo cargar '%s': %s\n",paths[i],IMG_GetError());
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
