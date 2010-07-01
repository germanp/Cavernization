/**
 * @file   mapa.cpp
 * @author german <german@german-desktop>
 * @date   Fri Jun 11 23:21:17 2010
 * 
 * @brief  Implementación de la clase Mapa
 *	   las descripciones de que hace cada función están en el .h
 * 
 */

#include <unistd.h>
#include <stdio.h>
#include "mapa.h"
#include "terrenos.cpp"

Mapa* Mapa::_instance=NULL;

Mapa::Mapa(const char* file): ANCHO(10), ALTO(10){ // Cambiar!!
  int m[100]= {0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,2,0,0,0,0,
	       0,0,1,0,0,0,0,1,0,0,
	       2,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,1,0,0,0,2,0,
	       0,0,0,0,0,0,0,0,0,0,
	       0,2,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,1,0,0,
	       0,0,1,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0};

  int i, length=ANCHO*ALTO;
  mapa=new Terreno *[100];
  for (i=0;i<length;i++){
    switch ( m[i] ){
    case 0:
      mapa[i]=new Pasto();
      break;
    case 1:
      mapa[i]=new PastoPiedra();
      break;
    case 2:
      mapa[i]=new PastoPiedra2();
      break;
    }
  }
}

Mapa::~Mapa(){
  printf("Borrando mapa.\n");
  delete[] mapa;
  ///////////////
  // REVISAR!! //
  ///////////////
}