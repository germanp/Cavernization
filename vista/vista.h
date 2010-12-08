/**
 * @file   dibujar.h
 * @author german <german@german-desktop>
 * @date   Sat Jun 19 12:18:47 2010
 * 
 * @brief  Este archivo contiene las definiciones de de las funciones
 * de carga de sprites y dibujado en la pantallla.
 * 
 * 
 */


#ifndef VISTA_H
#define VISTA_H

#include <SDL.h>
#include "terreno.h"
#include "mapa.h"
#include "objetomapa.h"
#include "sdl_vista.h"
#include "main.h"
#include "sdl_jugador.h"


#define FREC_PINTADO 1000/20 // Tiempo de refrezco 20 veces por segundo

/** 
 * Esta función es la que dibuja en la pantalla a partir del mapa
 *
 * @param screen Surface de SDL que representa la pantalla.
 *
 * @return 
 */
int Vista(void* v);

/**
 * Carga un tile desde un archivo en DataDir() y lo devuelve como un
 * surface de SDL.
 *
 */

SDL_Surface* cargarTile(const char* tileFile);
#endif // VISTA_H
