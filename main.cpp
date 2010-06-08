#include "personaje.h"
#include "thread.h"
#include <SDL_thread.h>
#include <SDL.h>

int main (){
  Personaje p(100);
  p.start();
  p.setDanio(10); // Le metemos una piña
  SDL_Delay(10000);
  p.setDanio(100); // Y ahora un terrible saque que lo deja knockout
  SDL_Delay(3000); // Esperamos hasta que termine el thread
  return 1;
}
