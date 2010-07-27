/**
 * @file   sdl_mapa.h
 * @author german <german@german-desktop>
 * @date   Sun Jul 25 22:55:57 2010
 * 
 * @brief  Subclase de Mapa que agrega la creacion de los Terrenos con
 * la implementacion de la vista.
 * 
 */

#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include "mapa.h"
#include "sdl_terrenos.cpp"

class SDL_Mapa : public Mapa{
 private:
 SDL_Mapa(): Mapa(){}
  ~SDL_Mapa(){}
 public:
  Terreno* crearTerreno(int c){
    Terreno* t;
    switch(c) {
    case ' ': t=new SDL_Tile<SDL_Pasto>(); break;
    case 'A': t=new SDL_Tile<SDL_PastoPiedra>(); break;
    default: t=0;
    }
    return t;
    
  }
 public:
  static SDL_Mapa* getInstance(){
    if ( Mapa::_instance == NULL ){
      _instance=new SDL_Mapa();
    }
    return (SDL_Mapa*)Mapa::_instance; 
  }
};

#endif // SDL_MAPA_H
