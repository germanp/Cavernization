/**
 * @file   main.cpp
 * @author german <german@german-desktop>
 * @date   Tue Jun 22 00:16:24 2010
 * 
 * @brief  Es el hilo principal del juego, llama a los hilos para
 * dibujar y controlar la entrada del usuario.
 *
 * @section TODO
 * - Destruir los objetos correctamente.
 */

#include "main.h"
#include "vista.h"
#include "terreno.h"
#include "sdl_builder.h"
#include "sdl_jugador.h"

/**
 * El main lanza el thread que dibuja la pantalla
 * y el que espera la entrada de usuario.
 *
 * @return
 */

int main (int argc, char* argv[]){
     SDL_Thread* thr_vista;
     SDL_Surface* screen; //
     SDL_Jugador* jug=new SDL_Jugador();
     char map_file[100];
     screen=Iniciar_Video(640,480,16,"Cavernization",SDL_SWSURFACE);
     sprintf(map_file,"%smapa.map",Data_Dir());
     Partida* p=new Partida(map_file,new SDL_Builder(),jug);
     P_Vista pVista = {screen,jug};
     thr_vista=SDL_CreateThread(Vista,&pVista);
     jug->entrada(screen);
     SDL_KillThread(thr_vista);
     SDL_FreeSurface(screen);
     return 0;
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

const char* Cavernization_Dir(){
  static const char* cav_dir=_Cavernization_Dir();
  return cav_dir;
}
const char* _Cavernization_Dir(){
  size_t size = 100;
  char *buffer;
  while (1){
    buffer = (char *) malloc (size);
    if ( getcwd (buffer, size) == buffer )
      return buffer;
    free (buffer);
    if ( errno != ERANGE )
      return 0;
    size *= 2;
  }
}

const char* Data_Dir(){
  static const char* data_dir=_Data_Dir();
  return data_dir;
}
const char* _Data_Dir(){
  const char* data="/data/";
  size_t size=strlen(Cavernization_Dir())+strlen(data);
  char* buffer=(char*)malloc(size);
  strncpy(buffer,Cavernization_Dir(),size);
  strncat(buffer,data,size);
  return buffer;
}
