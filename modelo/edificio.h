#ifndef EDIFICIO_H
#define EDIFICIO_H

/**
 * @file   edificio.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:04:58 2010
 *
 * @brief <Define las propiedades generales de los distintos edificios
 *         del juego (casas, cuarteles, templos).>
 *
 * @section TODO
 *  <>
 */

class Edificio: ObjetoConDuenio{

      protected:
                
                int vida;
                
                /**
                 * Devuelve el tipo de edificio: 1=casa, 2=cuartel, 3=templo
                 */ 
                int getTipo(Edificio e);
}
#endif // EDIFICIO_H
