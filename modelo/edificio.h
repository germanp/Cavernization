#ifndef EDIFICIO_H
#define EDIFICIO_H

/**
 * @file   edificio.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:04:58 2010
 *
 * @brief <Define las propiedades generales de los distintos edificios
 *         del juego (casas, cuarteles, templos).>
 *
 * @section TODO
 *  <>
 */

#include "objetoconduenio.h"

class Edificio:ObjetoConDuenio{
 protected:
  int vida;
 public:
  /**
   * Devuelve el tipo de edificio: 1=casa, 2=cuartel, 3=templo
   */
  virtual int getTipo()=0;
};

#endif // EDIFICIO_H
