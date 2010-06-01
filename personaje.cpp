#include "personaje.h"

Personaje::Personaje(int v):vida(v){}

void Personaje::execute(){
  int i;
  printf("\nSe lanzó el hilo del personaje.\n\n");
  while ( vida>0 ) {
    if ( vida < 100 ) vida++; // Se va curando cada 2 segundos
    printf("Vida = %d\n",vida);
    SDL_Delay(2000);
  }
  printf("\nSe murió el personaje.\n");
}
void Personaje::setDanio(int d){
  printf("Ouch! (Daño %d)\n",d);
  vida-=d;
}
