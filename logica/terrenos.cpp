/**
 * @file   terreno.cpp
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief Este archivo contiene los tipos de Terreno que existen y que
 * naturalmente heredan de la clase Terreno.
 *
 * @section TODO
 * 
 */

#ifndef TERRENOS_CPP
#define TERRENOS_CPP

#include "terreno.h"

class Pasto:public Terreno{
  inline int getTipo(){return 0;}
  inline bool esPisable(){return true;}
};

class PastoPiedra:public Terreno{
  inline int getTipo(){return 1;}
  inline bool esPisable(){return true;}
};

class PastoPiedra2:public Terreno{
  inline int getTipo(){return 2;}
  inline bool esPisable(){return false;}
};

#endif // TERRENOS_CPP
