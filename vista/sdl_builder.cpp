#include "sdl_builder.h"

SDL_Builder::SDL_Builder() : Builder() {}

Terreno* SDL_Builder::crearPasto(){
  return new SDL_Tile<Pasto>();
}
ObjetoMapa* SDL_Builder::crearFiel(unsigned int x, unsigned int y, Terreno* t){ 
  Fiel* f=new SDL_Sprite<Fiel>();
  f->setPos(x,y+f->getAlto());
  f->setCasilla(t);
  return f;
}

ObjetoMapa* SDL_Builder::crearCasa(unsigned int x, unsigned int y){
  Casa* f=new SDL_Tile<Casa>();
  f->setPos(x,y);
  return f;
 }
