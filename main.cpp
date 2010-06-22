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
#include "UI/input.h"
#include "UI/dibujar.h"
#include "modelo/terreno.h"
#include "modelo/mapa.h"
#include "main.h"

/**
 * El main lanza el thread que dibuja la pantalla
 * y el que espera la entrada de usuario.
 *
 * @return
 */
int main (){
     SDL_Thread* thr_gui;
     SDL_Thread* thr_input;
     Mapa* Map=Mapa::abrirMapa("mentira.map"); /* Todo los objetos del UML se guardan en esta matríz */
     SDL_Surface* screen;
  
     screen=Iniciar_Video(640,480,16,"Cavernization",SDL_HWSURFACE);
     thr_input=SDL_CreateThread(thr_Input,(void*)screen);
     thr_gui=SDL_CreateThread(thr_Dibujar,(void*)screen);
     SDL_Delay(1000);
     SDL_KillThread(thr_input);
     SDL_KillThread(thr_gui);
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
