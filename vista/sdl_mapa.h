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
//
#include "sdl_sprite.h"
#include "sdl_tile.h"
#include "terrenos.cpp"
#include "casa.h"
#include "fiel.h"

class SDL_Mapa : public Mapa{
 private:
 SDL_Mapa(): Mapa(){}
  SDL_Mapa(const Mapa&);
  SDL_Mapa& operator=(const SDL_Mapa&);
  ~SDL_Mapa(){}
public:
  Terreno** cargarMapa(const char* file){
    FILE* fd;
    int c=0,i=0;
    this->mapa=(Terreno**)malloc(4000*sizeof(Terreno*));
    fd=fopen(file,"r");
    if ( fd == NULL ) return 0;
    while( (c=fgetc(fd)) != EOF ) {
      switch(c) {
      case '-': {mapa[i]=new SDL_Tile<Pasto>(); break;}
	/* case 'o': mapa[i]=new SDL_Tile<SDL_PastoPiedra>(); break; */
	/* case 'O': mapa[i]=new SDL_Tile<SDL_PastoPiedra2>(); break; */
      case 'R':{
	Pasto* p1=new SDL_Tile<Pasto>();
	Fiel* f1=new SDL_Sprite<Fiel>();
	if ( ANCHO ) f1->setPos((i%ANCHO)*getLongCasilla(),(i/ANCHO)*getLongCasilla());
	else f1->setPos(i,0);
      	p1->ponerObjeto(f1);
      	mapa[i]=p1;
      	break;
      }
      case 'A':{
	Pasto* p1=new SDL_Tile<Pasto>();
	Casa* c1=new SDL_Tile<Casa>();
	if ( ANCHO ) c1->setPos((i%ANCHO)*getLongCasilla(),((i/ANCHO)-1)*getLongCasilla());
	else c1->setPos(i,0);
	p1->ponerObjeto(c1);
	mapa[i]=p1;
	break;
      }
      case '\n':
	if (!ANCHO)
	  ANCHO=i;
	break;
	}
      if ( c != '\n' ) {
	i++;
	if (!(i%4000)) mapa=(Terreno**)realloc(mapa,(i+4000)*sizeof(Terreno*));
      }
    }
    ALTO=i/ANCHO;
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
