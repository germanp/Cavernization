#ifndef OBJETO_CON_DUENIO_H
#define OBJETO_CON_DUENIO_H

/**
 * @file   objetoconduenio.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 10:58:58 2010
 *
 * @brief <Hereda de ObjetoMapa y define las propiedades generales
 *         de los distintos objetos (edificios, personajes)
 *         que tienen una relacion de pertenencia con los participantes.>
 *
 * @section TODO
 *  <>
 */

#include "objetomapa.h"

class ObjetoConDuenio: public ObjetoMapa{
 protected:
  int vida;
 public:
  ObjetoConDuenio(int x, int y);
  ObjetoConDuenio();
};

#endif // OBJETO_CON_DUENIO_H
