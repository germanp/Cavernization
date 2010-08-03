#ifndef CASA_H
#define CASA_H

/**
 * @file   casa.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:09:58 2010
 *
 * @brief <Edificio de tipo casa a donde acuden los fieles.>
 *
 * @section TODO
 *  <>
 */

#include "edificio.h"
//#include "fiel.h"

class Casa: public Edificio{
 public:
  Casa():Edificio(){}
  Casa(int x, int y): Edificio(x,y){ }
  ~Casa();
  //  Fiel* nuevoFiel();
};
#endif // CASA_H
