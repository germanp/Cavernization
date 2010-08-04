/**
 * @file   objetomapa.cpp
 * @author german <german@german-desktop>
 * @date   Mon Aug  2 14:21:09 2010
 * 
 * @brief  
 * 
 * 
 */


#include "objetomapa.h"
#include <stdio.h>

ObjetoMapa::ObjetoMapa(int x, int y) : x(x), y(y){}

ObjetoMapa::ObjetoMapa(){
  printf("Creado\n");
}

ObjetoMapa::~ObjetoMapa(){}
