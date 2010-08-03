#ifndef SDL_SPRITE_H
#define SDL_SPRITE_H

#include "sdl_vista.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../main.h"
#include <string.h>
//
#include "fiel.h"

struct SpriteData {
  char tmpl[100];
  unsigned int nEstados;
  unsigned int nOrientaciones;
  unsigned int nSprites[20][20];
};

template <class InstanciaTile> class SDL_Sprite : public InstanciaTile, public SDL_Vista {
private:
  static SDL_Surface* *** tiles;
  static int cantObj;

  static int nSprites[20][20];
  int cuadro;
  int reduccion;
public:
  SDL_Sprite();
  ~SDL_Sprite();
  SDL_Surface* getSurface(){
    reduccion++;
    if ( reduccion > 2 ){
      //      printf("Cuadro: %i, Total: %i, Red: %i\n",cuadro,nSprites[this->getEstado()][this->getOrientacion()],reduccion);
      if ( cuadro == nSprites[0][0]-1 ) cuadro=0; else cuadro++;
      reduccion=0;
    }
    return tiles[this->getOrientacion()][this->getEstado()][cuadro];
  }
  static void getSpriteData(struct SpriteData* data);
};

template<class InstanciaTile> int SDL_Sprite<InstanciaTile>::cantObj=0;
template<class InstanciaTile> SDL_Surface**** SDL_Sprite<InstanciaTile>::tiles=NULL;
template<class InstanciaTile> int SDL_Sprite<InstanciaTile>::nSprites[20][20];

template <class InstanciaTile> SDL_Sprite<InstanciaTile>::SDL_Sprite():InstanciaTile(),SDL_Vista(), cuadro(0), reduccion(0) {
  if ( tiles == NULL ){
    char aux[100],tmpl[100];
    int estado,orientacion,sprite;
    struct SpriteData data;
    this->getSpriteData(&data);
    sprintf(tmpl,"%ssprites/%s",Data_Dir(),data.tmpl);
    tiles=
      (SDL_Surface* ***)malloc(sizeof(**tiles)*data.nEstados);
    for ( estado=0; estado<data.nEstados; estado++ ){
      tiles[estado]=
    	(SDL_Surface* **)malloc(sizeof(***tiles)*data.nOrientaciones);
      
      for ( orientacion=0; orientacion<data.nEstados; orientacion++ ){

    	tiles[estado][orientacion]=
    	  (SDL_Surface* *)malloc(sizeof(***tiles)*data.nSprites[estado][orientacion]);
    	for ( sprite=0; sprite<data.nSprites[estado][orientacion] ; sprite++ ){ 
    	  sprintf(aux,tmpl,estado,orientacion,sprite);
	  printf("Cargando %s\n",aux);
    	  tiles[estado][orientacion][sprite]=IMG_Load(aux);
    	  if ( tiles[estado][orientacion][sprite] == NULL ) 
    	    printf("%s\n",IMG_GetError());
    	}
	nSprites[estado][orientacion]=sprite;
      }
    }
  }
  cantObj++;
}

template <class InstanciaTile> SDL_Sprite<InstanciaTile>::~SDL_Sprite(){
  cantObj--;
  if ( cantObj==0 ) {
    struct SpriteData data;
    this->getSpriteData(&data);
    //////////////////
    // COMPLETAR!!! //
    //////////////////
  }
}

#endif // SDL_SPRITE_H
