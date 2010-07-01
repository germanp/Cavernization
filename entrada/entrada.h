#ifndef INPUT_H
#define INPUT_H

/** 
 * Es un wrapper para que quede bien el prototipo de la función Input
 * 
 * @param v Parámetro para el thread.
 * 
 * @return 
 */
int thr_Input(void* v);

/** 
 * Esta función es la que gestiona la entrada del mouse
 *
 * @param screen El surface principal del juego.
 *
 * @return 
 */
inline void Input(SDL_Surface* screen);

#endif // INPUT_H
