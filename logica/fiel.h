#ifndef FIEL_H
#define FIEL_H

/**
 * @file   fiel.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:40:58 2010
 *
 * @brief Personaje de tipo Fiel
 *
 * @section TODO
 *
 */

#include "personaje.h"
#include "arbol.h"
#include "edificio.h"

class Fiel : public Personaje{
 public:
 Fiel() : Personaje(0,0,21,26,3,NULL) {}
 Fiel(unsigned int x, unsigned int y, Terreno* casilla) :
  Personaje(x,y,21,26,3,casilla){ }
  ~Fiel();
  /**
   * Ordena a un fiel a construir un edificio
   * @param e Edificio a construir
   */
  void construir(Edificio e);
  /**
   * Ordena talar un arbol para construir algun tipo de edificio
   * @param a Arbol a talar
   */
  void talar(Arbol a);
};
#endif // FIEL_H
