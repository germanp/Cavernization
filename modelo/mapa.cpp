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

Mapa* Mapa::_instance=NULL;

Mapa* Mapa::getInstance(const char* file){
  if (!_instance){
    _instance=new Mapa(file);
    printf("Nuevo Mapa\n");
  }
  return _instance;
}
inline Mapa* Mapa::getInstance(){ return _instance; }

Mapa::Mapa(const char* file){ // Cambiar!!
  ANCHO=10;
  ALTO=10;
// TODO: Implementar la carga del mapa
}

inline int Mapa::getAncho(){ return ANCHO; }
inline int Mapa::getAlto(){ return ALTO; }

Terreno* Mapa::operator[](int pos){
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
