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


#ifndef DIBUJAR_H
#define DIBUJAR_H

#include <SDL.h>

/** 
 * Es un wrapper para que quede bien el prototipo de la función Dibujar
 * 
 * @param v Parámetro para el thread.
 * 
 * @return 
 */
int thr_Dibujar(void* v);

/** 
 * Esta función es la que dibuja en la pantalla a partir del mapa
 *
 * @param Map Mapa del juego que está corriendo. La función barre este
 * mapa y lo va dibujando a cada momeno 
 *
 * @return 
 */
inline void Dibujar(SDL_Surface* screen);

/** 
 * Carga los tiles en los SDL_surfaces
 * 
 * 
 * @return Vector de SDL_Surface* con los tiles cargados
 */
SDL_Surface** Cargar_Tiles();

#endif // DIBUJAR_H
