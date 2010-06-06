#ifndef TABLERO_H
#define TABLERO_H

/**
 * @file   tablero.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief <Se encarga de agregar y mostrar los objetos en el tablero>
 *
 * @section TODO
 *  <>
 */

class Tablero{
      private:
             /**
              * Medidas del tablero 
              */ 
             int ancho;
             int alto;
      public:
             /**
              * Objeto de tipo terreno que guerda los diferentes 
              * objetos mapa del tablero
              */
             Terreno matriz[ancho][alto];
             /**
               * Muestra los distintos objetos en la 
               * posición correspondiente del tablero
               *
               * @param nada
               *
               * @return nada
               */
             void dibujar();
               /**
               * Agrega un nuevo personaje al tablero
               *
               * @param objeto de ObjetoMapa
               *
               * @return nada
               */
             void nuevoObjetoMapa(ObjetoMapa o);
             Tablero(int ancho,int alto);
}
#endif // TABLERO_H
