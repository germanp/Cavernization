#ifndef TERRENO_H
#define TERRENO_H

/**
 * @file   terreno.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief Define el terreno sobre el cual se dispondra
 *         a los distintos personajes y el orden en que seran 
 *         dibujados.
 *
 * @section TODO
 *  <>
 */

#include "objetomapa.h"

class Terreno{
 protected:
  //  ObjetoMapa objetos[];
 public:
  /**
   * Devuelve el tipo del terreno identificado por un
   * número para ser traducido en una imágen por la vista
   */ 
  virtual int getTipo()=0;
  /**
   * Permite conocer si el terreno es pisable o no.
   * La clase hija implementa este método y devuelve según
   * 0 o 1 corresponda
   */ 
  virtual bool esPisable()=0;
};
#endif // TERRENO_H
