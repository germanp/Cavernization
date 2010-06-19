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

Mapa* Mapa::abrirMapa(const char* file){
  if (!_instance){
    _instance=new Mapa(file);
    printf("Nuevo Mapa\n");
  }
  return _instance;
}

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

inline int Mapa::getAncho(){ return ANCHO; }
inline int Mapa::getAlto(){ return ALTO; }

/*Terreno* Mapa::operator[](int pos){
  return mapa[pos];
  }*/
Terreno* Mapa::getMapa(unsigned int pos){
  return mapa[pos];
}

Mapa::~Mapa(){
  printf("Borrando mapa...\n");
  delete[] mapa;
  /*  int x,y;
  for ( y=0; y<ALTO; y++){
    for ( x=0; x<ANCHO; x++){
      ////////////////////////////////////////////////////
      // Arreglar esto y adaptarlo a lo que va a quedar //
      ////////////////////////////////////////////////////
      delete mapa[y*ANCHO+x];
    }
    }*/
}
