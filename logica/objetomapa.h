#ifndef OBJETO_MAPA_H
#define OBJETO_MAPA_H

/**
 * @file   objetomapa.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief <Clase padre de la cual heredan los distintos tipos de objetos
 *         (arboles, casas, personajes).
 *         Define los distintos atributos y comportamiento generales de estos
 *         objetos>
 *
 * @section TODO
 *
 */

class ObjetoMapa {
 protected:
  /**
   * Variable para la medidas y posicion del objeto
   */
  int ancho,alto,x,y;
 public:
  ObjetoMapa(int x, int y) : x(x), y(y){}
  ObjetoMapa(){}
  int getX(){ return x; }
  int getY(){ return y; }
  virtual ~ObjetoMapa(){}
};
#endif // OBJETO_MAPA_H
