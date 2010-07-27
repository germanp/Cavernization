/**
 * @file   sdl_terrenos.cpp
 * @author german
 * @date   Sat Jul  3 00:17:33 2010
 * 
 * @brief  Este fichero contiene las clases correspondientes a los
 * distintos tipos de terrenos y agregan el SDL_Surface
 * correspondiente para poder pintarlo en la pantalla.
 * 
 */

#ifndef SDL_TERRENOS_CPP
#define SDL_TERRENOS_CPP

#include <SDL.h>
#include "sdl_tile.h"
#include "terrenos.cpp"

class SDL_Pasto : public Pasto {
public:
  const char* getTileFile(){ return "pasto0.png"; }
};

class SDL_PastoPiedra : public PastoPiedra {
public:
  const char* getTileFile(){ return "pasto1.png"; }
};

class SDL_PastoPiedra2 : public PastoPiedra2 {
public:
  const char* getTileFile(){ return "pasto2.png"; }
};

#endif // SDL_TERRENOS_CPP
