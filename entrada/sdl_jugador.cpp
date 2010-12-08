/**
 * @file   sdl_jugador.cpp
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Fri Jun  11 22:00:58 2010
 *
 * @brief Implementación de los metodos de la clase SDL_Jugador
 *
 * @section TODO
 *  <>
 */

#include <SDL.h>

#include "sdl_jugador.h"

void SDL_Jugador::entrada(SDL_Surface*s){
  SDL_Event evento;
  Mapa& mapa = *Mapa::getInstance();
  Personaje* personaje=NULL;

  for( ; ; ) {
    while(SDL_PollEvent(&evento)) {
      if(evento.type == SDL_KEYDOWN) {
	if(evento.key.keysym.sym == SDLK_ESCAPE)
	  return;
      }
      if(evento.type == SDL_QUIT)
	return;

      if(evento.type == SDL_MOUSEBUTTONDOWN) {
	printf("X: %d - Y: %d\n", evento.button.x,evento.button.y);
	if(evento.button.button == 1){
	  seleccion = mapa((int)evento.button.x/mapa.getLongCasilla(),(int)evento.button.y/mapa.getLongCasilla())->getContenido();
	  personaje=dynamic_cast<Personaje*>(seleccion);
	} else {
	  if ( personaje ) personaje->caminar(evento.button.x,evento.button.y);
	}
      }
    }
    SDL_Delay(FREC_INPUT);
  }
}
