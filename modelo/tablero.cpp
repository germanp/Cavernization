#include "tablero.h"
#include "terreno.h"

/**
 * @file   tablero.cpp
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief <>
 *
 * @section TODO
 *  <>
 */

Tablero::Tablero(int ancho, int alto)
{
     this->ancho=ancho;
     this->alto=alto;                
} 
void Tablero::dibujar()
{
    /**
     * Recorro el tablero y muestro los valores de cada posicion.
     */
     for(int i=0;i<ancho;i++)
     {
             for(int j=0;j<alto;j++)
             {
                     cout<<matriz[i][j];
             }
     }                                  
}
void Tablero::nuevoObjetoMapa(ObjetoMapa o)
{
    /**
     * Recorro el tablero y agrego el objeto cuando coincide 
     * la posicion.
     */
     for(int i=0;i<ancho;i++)
     {
             for(int j=0;j<alto;j++)
             {
                     /**
                      * Comparo la posicion ancho alto del terreno 
                      * con x y del objeto
                      */
                     if(i==o.x && j==o.y)
                     {
                               matriz[i][j]=p;
    
                     }
             }
     }
}
