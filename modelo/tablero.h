#ifndef TABLERO_H
#define TABLERO_H

/**
 * @file   tablero.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief <Se encarga de agregar y mostrar los distintos objetos sobre el tablero>
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
              * Objeto de tipo Terreno que guarda los diferentes 
              * terrenos del mapa
              */
             Terreno terrenos[ancho][alto];
             
             /**
              * Objeto de tipo ObjetoMapa que guarda los diferentes 
              * objetos (edificios, arboles, personajes, etc.) del mapa
              */
             ObjetoMapa objetos[ancho][alto];
             
             /**
               * Muestra los distintos objetos en la 
               * posición correspondiente del tablero
               */
             void dibujar();
             
             /**
               * Agrega un nuevo personaje al tablero
               *
               * @param ObjetoMapa o
               */
             void nuevoObjetoMapa(ObjetoMapa o);
             
}
#endif // TABLERO_H
