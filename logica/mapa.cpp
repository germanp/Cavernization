/**
 * @file   mapa.cpp
 * @author german <german@german-desktop>
 * @date   Fri Jun 11 23:21:17 2010
 * 
 * @brief  Implementación de la clase Mapa
 *	   las descripciones de que hace cada función están en el .h
 * @section TODO:
 *		 - Buscar la manera de sacar la parte de SDL de aca.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mapa.h"
#include "terreno.h"

Mapa* Mapa::_instance=NULL;
     
int Mapa::cargarMapa(const char* file){
  FILE* fd;
  int c=0,i=0;
  this->mapa=(Terreno**)malloc(4000*sizeof(Terreno*));
  fd=fopen(file,"r");
  if ( fd == NULL ) return 0;
  while( (c=fgetc(fd)) != EOF) {
    if (c == '\n') {
      if (!ANCHO)
  	ANCHO=i;
    } else {
      mapa[i]=crearTerreno(c);
      i++;
      if (!(i%4000)) this->mapa=(Terreno**)realloc(mapa,(i+4000)*sizeof(Terreno*));
    }
  }
  ALTO=i/ANCHO;
  return 1;
}

void Mapa::liberarMapa(){
  delete Mapa::_instance;
}

Mapa::~Mapa(){
  printf("Borrando mapa.\n");
  delete[] mapa;
}
