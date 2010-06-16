#ifndef DIBUJAR_H
#define DIBUJAR_H


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

#endif // DIBUJAR_H
