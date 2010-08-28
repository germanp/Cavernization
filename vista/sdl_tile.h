#ifndef SDL_TILE_H
#define SDL_TILE_H

#include "sdl_vista.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../main.h"

template <class InstanciaTile> class SDL_Tile : public InstanciaTile, public SDL_Vista {
private:
  static SDL_Surface* tile;
  static int cantObj;
public:
  SDL_Tile();
  ~SDL_Tile();
  SDL_Surface* getSurface(){ return tile; }
  static const char* getTileFile();
};

template<class InstanciaTile> int SDL_Tile<InstanciaTile>::cantObj=0;
template<class InstanciaTile> SDL_Surface* SDL_Tile<InstanciaTile>::tile=NULL;

template <class InstanciaTile> SDL_Tile<InstanciaTile>::SDL_Tile():InstanciaTile(),SDL_Vista() {
  if ( tile == NULL ){
    char aux[200];
    sprintf(aux,"%stiles/%s",Data_Dir(),getTileFile());
    tile=IMG_Load(aux);
    printf("Cargando %s\n",aux);
    if ( tile == NULL ) 
      printf("%s\n",IMG_GetError());
  }
  cantObj++;
}

template <class InstanciaTile> SDL_Tile<InstanciaTile>::~SDL_Tile(){
  cantObj--;
  if ( cantObj==0 ) {
    SDL_FreeSurface(tile);
    tile=NULL;
    printf("Liberando tile %s...\n",getTileFile());
  }
}



#endif // SDL_TILE_H
