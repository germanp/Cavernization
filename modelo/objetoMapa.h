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
 *  <>
 */

class ObjetoMapa{
      private:
              /**
               * Variable para la medidas y posicion del objeto
               */
              int ancho,alto,x,y;
      public:
             /**
              * Metodo que devuelve el nombre/url del tile del objeto
              *
              * @return String
              */
             String getTile();
      }
#endif // OBJETO_MAPA_H
