#ifndef PREDICADOR_H
#define PREDICADOR_H

/**
 * @file   predicador.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:30:58 2010
 *
 * @brief <Personaje de tipo predicador.>
 *
 * @section TODO
 *  <>
 */

#include "personaje.h"

class Predicador: public Personaje{
  
 public:
  /**
   * Predica a los fieles
   */
  void predicar();
};
#endif // PREDICADOR_H
