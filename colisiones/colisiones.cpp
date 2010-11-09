/**
 * @file   colisiones.cpp
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Nov  9 17:46:16 2010
 *
 * @brief <Implementación de las funciones dedicadas a la detección de colisiones.>
 *
 * @section TODO
 *  <>
 */

#include "personaje.h"

bool hayColision(Personaje un_personaje, Personaje otro_personaje){
     int ancho1, alto1, ancho2, alto2, x1, y1, x2, y2;
     
     /**
      * Variables para guardar la posición y las medidas del personaje  
      */
      
     ancho1 = un_personaje.getAncho();
     alto1 = un_personaje.getAlto();
     
     ancho2 = otro_personaje.getAncho();
     alto2 = otro_personaje.getAlto();
     
     x1 = un_personaje.getX();
     y1 = un_personaje.getY();
          
     x2 = otro_personaje.getX();
     y2 = otro_personaje.getY();
     
     /**
      * Se compara la posición y las medidas del personaje 1 contra la posición del 
      * personaje 2 y viceversa.
      * Si se tocan sale por true.
      * Funca teniendo en cuenta que sean cuadrados, sino se chocan antes de chocarse.
      */
     
     if( ((x1 + ancho1) > x2) && 
         ((y1 + alto1) > y2) && 
         ((x2 + ancho2) > x1) && 
         ((y2 + alto2) > y1))
         return true;
         
     return false;  
     
}
