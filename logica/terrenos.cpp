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
#include "objetomapa.h"

class Pasto:public Terreno{
public:
  Pasto(ObjetoMapa* o):Terreno(o){}
  Pasto():Terreno(){}
};

class PastoPiedra:public Terreno{
public:
  PastoPiedra(ObjetoMapa* o):Terreno(o){}
  PastoPiedra():Terreno(){}
};

class PastoPiedra2:public Terreno{
public:
  PastoPiedra2(ObjetoMapa* o): Terreno(o){}
  PastoPiedra2(): Terreno(){}
  inline bool esPisable(){return false;}
};

#endif // TERRENOS_CPP
