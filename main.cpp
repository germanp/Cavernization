/**
 * @file   main.cpp
 * @author german <german@german-desktop>
 * @date   Tue Jun 22 00:16:24 2010
 * 
 * @brief  Es el hilo principal del juego, llama a los hilos para
 * dibujar y controlar la entrada del usuario.
 *
 * @section TODO
 * - Agregar un sistema para que el thread input() pueda comunicarse
 * con el de dibujar() para que se interrumpa y libere la memoria que usó.
 */


#include <SDL_thread.h>
#include <SDL.h>
#include "entrada.h"
#include "vista.h"
#include "terreno.h"
#include "mapa.h"
#include "main.h"

/**
 * El main lanza el thread que dibuja la pantalla
 * y el que espera la entrada de usuario.
 *
 * @return
 */

int main (int argc, char* argv[]){
     SDL_Thread* thr_vista;
     SDL_Thread* thr_entrada;
     SDL_Surface* screen;

     Mapa::abrirMapa(Cargar_Mapa(),10,10); /* Todo los objetos del UML se guardan en esta matríz */
  
     screen=Iniciar_Video(640,480,16,"Cavernization",SDL_HWSURFACE);
     thr_entrada=SDL_CreateThread(Entrada,(void*)screen);
     thr_vista=SDL_CreateThread(Vista,(void*)screen);
     SDL_Delay(1000);
     SDL_KillThread(thr_entrada);
     SDL_KillThread(thr_vista);
     SDL_FreeSurface(screen);
     return 1;
}

SDL_Surface* Iniciar_Video(int w, int h,int depth,const char* titulo, int flags){
     SDL_Surface * screen;
     if (SDL_Init (SDL_INIT_VIDEO) == -1)
     {
	  printf ("%s\n", SDL_GetError ());
	  return NULL;
     }
     
     atexit (SDL_Quit);
  
     SDL_WM_SetCaption (titulo, NULL);
	
     screen = SDL_SetVideoMode (w, h, depth, flags);
  
     if (! screen)
     {
	  printf ("%s\n", SDL_GetError ());
	  return NULL;
     }
     
     return screen;
}
