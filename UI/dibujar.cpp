/**
 * @file   dibujar.cpp
 * @author Germán Podestá
 * @date   Sun Jun 13 12:03:40 2010
 * 
 * @brief  Este archivo tiene las rutinas para dibujar el juego en la pantalla
 * 
 * 
 */


#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <mapa.h>
#include "dibujar.h"
#include "terreno.h"

#define  REFREZCO 1000/50 // Tiempo de refrezco 50 veces por segundo

int thr_Dibujar(void* v){
  SDL_Surface* s=(SDL_Surface*)v;
  Dibujar(s);
  return 0;
}

inline void Dibujar(SDL_Surface* screen){
  
  
  while (1){
    Mapa Map=Mapa::getInstance();
    int i;
    for (i=0; i<100 ; i++ ){
      Terreno* t=Map[i];
      printf("Imprimir tile tipo %d...\n",t->getTipo());
      SDL_Delay(REFREZCO);
    }
  }
}
