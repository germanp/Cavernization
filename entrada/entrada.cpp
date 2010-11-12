/**
 * @file   entrada.cpp
 * @author german <german@german-desktop>
 * @date   Tue Aug  3 17:30:08 2010
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
int Entrada(SDL_Surface* s){
     SDL_Event evento;
     Mapa& mapa = *Mapa::getInstance();
     Personaje* personaje=NULL;
     ObjetoMapa* o;
     for( ; ; ) {
       while(SDL_PollEvent(&evento)) {
	 if(evento.type == SDL_KEYDOWN) {
	   if(evento.key.keysym.sym == SDLK_ESCAPE)
	     return 0;
	 }
	 if(evento.type == SDL_QUIT)
	   return 0;

	 if(evento.type == SDL_MOUSEBUTTONDOWN) {
	   o = mapa((int)evento.button.x/mapa.getLongCasilla(),(int)evento.button.y/mapa.getLongCasilla())->getContenido();
	   printf("X: %d - Y: %d\n", evento.button.x,evento.button.y);
	   if(evento.button.button == 1){
	     personaje=dynamic_cast<Personaje*>(o);
	   } else {
	     if ( personaje ) personaje->caminar(evento.button.x,evento.button.y);
	   }
	 }
       }
       SDL_Delay(FREC_INPUT);
     }
}
