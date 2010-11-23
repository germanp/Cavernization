#ifndef EDIFICIO_H
#define EDIFICIO_H

/**
 * @file   edificio.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:04:58 2010
 *
 * @brief  Define las propiedades generales de los distintos edificios
 *         del juego (casas, cuarteles, templos).
 *
 * @section TODO
 *  <>
 */

#include "objetoconduenio.h"

class Edificio:public ObjetoConDuenio {
 protected:
  int vida;
 public:
 Edificio(int x, int y, int ancho, int alto) : ObjetoConDuenio(x,y,ancho,alto){}
};

#endif // EDIFICIO_H
