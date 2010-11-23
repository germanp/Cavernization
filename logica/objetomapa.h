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
  unsigned int ancho,alto,x,y;
 public:
  ObjetoMapa(unsigned int x, unsigned int y, unsigned int ancho, unsigned int alto);
  ObjetoMapa();
  int getX(){ return x; }
  int getY(){ return y; }
  int getAncho(){ return ancho; }
  int getAlto(){ return alto; }
  virtual void setPos(unsigned int x, unsigned int y){ this->x=x; this->y=y; }
  virtual ~ObjetoMapa();
};
#endif // OBJETO_MAPA_H
