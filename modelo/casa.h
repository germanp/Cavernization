#ifndef CASA_H
#define CASA_H

/**
 * @file   casa.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:09:58 2010
 *
 * @brief <Edificio de tipo casa a donde acuden los fieles.>
 *
 * @section TODO
 *  <>
 */

class Casa: Edificio{

      public:
             /**
              * Agrega un fiel a la casa
              */ 
             Fiel nuevoFiel();
}
#endif // CASA_H
