#include <SDL_thread.h>
#include <SDL.h>
#include "UI/input.h"
#include "UI/dibujar.h"
#include "modelo/terreno.h"
#include "modelo/mapa.h"


/**
 * El main lanza el thread que dibuja la pantalla
 * y el que espera la entrada de usuario.
 *
 * @return
 */
int main (){
  SDL_Thread* thr_GUI;
  SDL_Thread* thr_Input;
  Mapa* Map=Map->getInstance("mentira.map"); /* Todo los objetos del UML se guardan en esta matríz */
  thr_Input=SDL_CreateThread(User_Input,NULL);
  thr_GUI=SDL_CreateThread(Dibujar,NULL);
  SDL_Delay(1000);
  //  delete Map;
  return 1;
}
