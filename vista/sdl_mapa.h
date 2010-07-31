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
#include "sdl_tile.h"
//
//#include "terrenos.cpp"

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
      case '-': mapa[i]=new SDL_Tile<Pasto>(); break;
	/* case 'o': mapa[i]=new SDL_Tile<SDL_PastoPiedra>(); break; */
	/* case 'O': mapa[i]=new SDL_Tile<SDL_PastoPiedra2>(); break; */
      case '/': 
	if ( (c=fgetc(fd)) == '\\' ){
	  ObjetoMapa* o=new SDL_Tile<Casa>();
	  Pasto* p1=new SDL_Tile<Pasto>();
	  Pasto* p2=new SDL_Tile<Pasto>();
	  p1->ponerObjeto(o);
	  p2->ponerObjeto(o);
	  mapa[i++]=p1;
	  mapa[i]=p2;
	  break;
	} else {
	  fprintf(stderr,"Error en la carga de mapa: Carácter '%c' inválido, se esperaba un '\\' (en el caracter nº %i). ",c,i);
	  return 0;
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
    printf("Lalallala");
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
