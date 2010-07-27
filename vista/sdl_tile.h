#ifndef SDL_TILE_H
#define SDL_TILE_H

#include "sdl_vista.h"
#include <SDL.h>
#include <SDL_image.h>
#include "sdl_terrenos.cpp"
#include "terrenos.cpp"
#include "../main.h"

template <class InstanciaTile> class SDL_Tile : public InstanciaTile, public SDL_Vista {
private:
  static SDL_Surface* tile;
  static int cantObj;
public:
  SDL_Tile();
  ~SDL_Tile();
  SDL_Surface* getSurface(){ return tile; }
};

template<class InstanciaTile> int SDL_Tile<InstanciaTile>::cantObj=0;
template<class InstanciaTile> SDL_Surface* SDL_Tile<InstanciaTile>::tile=NULL;

template <class InstanciaTile> SDL_Tile<InstanciaTile>::SDL_Tile(){
  if ( cantObj == 0 ){
    char aux[200];
    sprintf(aux,"%stiles/%s",Data_Dir(),this->getTileFile());
    tile=IMG_Load(aux);
    if ( tile == NULL ) 
      printf("%s\n",IMG_GetError());
  }
}

template <class InstanciaTile> SDL_Tile<InstanciaTile>::~SDL_Tile(){
  cantObj--;
  if ( cantObj==0 ) SDL_FreeSurface(tile);
}

#endif // SDL_TILE_H
