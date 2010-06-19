/**
 * @file   main.h
 * @author Germán Podestá
 * @date   Wed Jun 16 12:47:45 2010
 * 
 * @brief  Este archivo contiene las rutinas de inicialización
 * necesarias para el juego.
 * 
 */

#include <SDL.h>

/** 
 * Inicia una ventana con SDL y le setea el título.
 * 
 * @param w Ancho de la ventana en píxeles.
 * @param h Alto de la ventana en píxeles.
 * @param depth Cantidad de colores por píxel BPP.
 * @param flags Flags para SDL.
 * @param titulo Título de la ventana.
 * 
 * @return 
 */
SDL_Surface* Iniciar_Video(int w, int h, int depth, const char* titulo, int flags);