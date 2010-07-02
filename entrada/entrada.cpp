/**
 * @file   dibujar.cpp
 * @author Germán Podestá
 * @date   Sun Jun 13 12:03:40 2010
 * 
 * @brief  Este archivo tiene las rutinaas para dibujar el juego en la pantalla
 * 
 * 
 */


#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <mapa.h>
#include "entrada.h"

#define  FREC_INPUT 100 // Tiempo de refrezco 10 veces por segundo

int Entrada(void* v){
  SDL_Surface* screen=(SDL_Surface*)v;
  while (1){
    ///////////////////////////////////////
    // TODO: Implementar el dibujamiento //
    ///////////////////////////////////////
    printf("Esperando entrada...\n");
    SDL_Delay(FREC_INPUT);
  }
}
