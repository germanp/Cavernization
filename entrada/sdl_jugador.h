#ifndef SDL_JUGADOR_H
#define SDL_JUGADOR_H

/**
 * @file   jugadorhumano.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Fri Jun  11 22:00:58 2010
 *
 * @brief Esta clase se encarga de la interfaz con el usuario. Recibe
 * las órdenes del jugador y ordena a los personajes a caminar,
 * atacar, etc. según indique el usuario.
 *
 * @section TODO
 *  
 */

#include "jugador.h"

#define  FREC_INPUT 100 // Tiempo de refrezco 10 veces por segundo

class SDL_Jugador : public Jugador {
 private:
  ObjetoMapa* seleccion;
 public:
  void entrada(SDL_Surface* s);
  /**
   * Devuelve el objeto seleccionado por el jugador. NULL si no hay nada
   */
  ObjetoMapa* getSeleccion() { return seleccion; }
};

#endif // SDL_JUGADOR_H
