/**
 * @file   tiles.cpp
 * @author german <german@german-desktop>
 * @date   Mon Aug  2 17:15:05 2010
 * 
 * @brief  En este fichero se ponen las especializaciones de la clase
 * SDL_Tile para indicar que tipo de objeta carga cada archivo .png
 * 
 */

#ifndef TILES_CPP
#define TILES_CPP

#include "sdl_tile.h"
#include "terrenos.cpp"
#include "casa.h"
//
#include "fiel.h"
//

template<> const char* SDL_Tile<Pasto>::getTileFile(){
  return "pasto0.png";
}

template<> const char* SDL_Tile<Casa>::getTileFile(){
  return "casa.png";
}

template<> const char* SDL_Tile<Fiel>::getTileFile(){
  return "fiel.png";
}

#endif // TILES_CPP
