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

#define FREC_PINTADO 1000/50 // Tiempo de refrezco 50 veces por segundo

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
 * Carga los tiles en un array SDL_Surfaces. El vector es alocado con
 * malloc() y debe ser liberado con free().
 * 
 * 
 * @return Vector de SDL_Surface* con los tiles cargados
 */
SDL_Surface** Cargar_Tiles();

/** 
 * Libera un array de SDL_Surfaces
 * 
 * @param s Array de surfaces a liberar.
 */
void Liberar_Tiles(SDL_Surface** s);

#endif // DIBUJAR_H
