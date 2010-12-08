/**
 * @file   mapa.cpp
 * @author german <german@german-desktop>
 * @date   Fri Jun 11 23:21:17 2010
 * 
 * @brief  Implementación de la clase Mapa
 *	   las descripciones de que hace cada función están en el .h
 * @section TODO:
 *
 */

#include "mapa.h"

Mapa* Mapa::_instance=NULL;
     
void Mapa::liberarMapa(){
  delete Mapa::_instance;
}

Mapa::Mapa(Terreno** mapa,Builder* build,unsigned int ancho,unsigned int alto, unsigned int longCasilla) :
  ANCHO(ancho), ALTO(alto), LONGCASILLA(longCasilla) {
  this->mapa=mapa;
}

Mapa::~Mapa(){
  printf("Borrando mapa.\n");
  delete[] mapa;
  delete build;
}

int Mapa::cargarMapa(const char* file, Builder* build){
  FILE* fd;
  int c=0,i=0;
  const unsigned int LONGCASILLA=32;
  unsigned int x, y, ANCHO=0, ALTO=0;

  Terreno** mapa=(Terreno**)malloc(4000*sizeof(Terreno*));
  fd=fopen(file,"r");
  if ( fd == NULL ) return 0;
  while( (c=fgetc(fd)) != EOF ) {
    switch(c) {
    case '-': {
      mapa[i]=build->crearPasto();
      break;
    }
      /* case 'o': mapa[i]=new SDL_Tile<SDL_PastoPiedra>(); break; */
      /* case 'O': mapa[i]=new SDL_Tile<SDL_PastoPiedra2>(); break; */
    case 'R':{
      Terreno* p1=build->crearPasto();
      if ( ANCHO ) {
    	x=(i%ANCHO)*LONGCASILLA+LONGCASILLA/2;
    	y=(i/ANCHO)*LONGCASILLA;
      } else {
    	x=i;
    	y=0;
      }
      ObjetoMapa* f1=build->crearFiel(x,y,p1);
      p1->ponerObjeto(f1);
      mapa[i]=p1;
      break;
    }
    case 'A':{
      Terreno* p1=build->crearPasto();

      if ( ANCHO ) {
	x=(i%ANCHO)*LONGCASILLA+LONGCASILLA/2;
	y=(i/ANCHO)*LONGCASILLA+LONGCASILLA;
      } else {
	x=i;
	y=0;
      }
      ObjetoMapa* c1=build->crearCasa(x,y);
      p1->ponerObjeto(c1);
      mapa[i]=p1;
      break;
    }
    case '\n':
      if (!ANCHO)
	ANCHO=i;
      break;
    default:
      return 0;
    }
    if ( c != '\n' ) {
      i++;
      if (!(i%4000)) mapa=(Terreno**)realloc(mapa,(i+4000)*sizeof(Terreno*));
    }
  }
  ALTO=i/ANCHO;
  _instance=new Mapa(mapa,build,ANCHO,ALTO,LONGCASILLA);
}
