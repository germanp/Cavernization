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
#include <stdio.h>
#include "mapa.h"
#include "terreno.h"

Mapa* Mapa::_instance=NULL;

Mapa::Mapa(Terreno** _mapa, int _ancho, int _alto): ANCHO(_ancho), ALTO(_alto){
  mapa=_mapa;
}

Mapa::~Mapa(){
  printf("Borrando mapa.\n");
  delete[] mapa;
}
