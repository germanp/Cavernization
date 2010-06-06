#ifndef OBJETO_MAPA_H
#define OBJETO_MAPA_H

/**
 * @file   objetoMapa.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief <>
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
              * Metodo que devuelve el nombre del tile del objeto
              *
              * @param 
              *
              * @return 
              */
             String getTile();
             ObjetoMapa(int ancho,int alto,int x,int y);
      }
#endif // OBJETO_MAPA_H
