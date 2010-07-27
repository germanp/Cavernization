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

#define FREC_PINTADO 1000/50 // Tiempo de refrezco 50 veces por segundo

/** 
 * Esta función es la que dibuja en la pantalla a partir del mapa
 *
 * @param screen Surface de SDL que representa la pantalla.
 *
 * @return 
 */
int Vista(void* v);

/** 
 * Carga los tiles en un array SDL_Surfaces. El vector es alocado con
 * malloc() y debe ser liberado con free().
 *
 * @param tmpl Cadena de texto template al estilo printf con el path
 * de las imágenes. Debe contener un %d para ir numerando las imágenes.
 * 
 * @return Vector de SDL_Surface* con los tiles cargados
 */
SDL_Surface** Cargar_Tiles(const char* tmpl, int n);

/** 
 * Libera un array de SDL_Surfaces
 * 
 * @param s Array de surfaces a liberar.
 */
void Liberar_Tiles(SDL_Surface** s);


Terreno** Cargar_Mapa();

Terreno** leerMapa(const char* file,int* width);

#endif // VISTA_H
