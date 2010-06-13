/**
 * @file   mapa.cpp
 * @author german <german@german-desktop>
 * @date   Fri Jun 11 23:21:17 2010
 * 
 * @brief  Implementación de la clase Mapa
 *	   las descripciones de que hace cada función están en el .h
 * 
 */

#include "mapa.h"
#include <stdio.h>

Mapa* Mapa::_instance=NULL;

Mapa* Mapa::getInstance(const char* file){
  if (!_instance){
    _instance=new Mapa(file);
    printf("Nuevo Mapa\n");
  }
  return _instance;
}
inline Mapa* Mapa::getInstance(){ return _instance; }

Mapa::Mapa(const char* file){
// TODO: Implementar la carga del mapa
}

inline int getAncho(){ return ANCHO; }
inline int getAlto(){ return ALTO; }

inline Terreno* operator[](int pos){
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
