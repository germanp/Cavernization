#ifndef ARBOL_H
#define ARBOL_H

/**
 * @file   arbol.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief <Clase Arbol, de la cual heredan las subclases ArbolChico, 
 *         ArbolMediano y ArbolGrande.
 *         Define los atributos y metodos comunes a estas clases.>
 *
 * @section TODO
 *  <>
 */

#include "objetomapa.h"

class Arbol:ObjetoMapa{
 protected:
  /**
   *  Cantidad de piezas de madera que forman la imagen del arbol.
   */ 
  int piezasMadera;
  /**
   * Asigna el tipo de madera del arbol. 
   */ 
  inline void setMadera();
  /**
   * Devuelve el tipo de arbol, 1=arbol chico, 2=arbol mediano, 
   * 3=arbol grande. 
   *
   * @return int
   */
  inline int getTipo();
};
#endif // ARBOL_H
