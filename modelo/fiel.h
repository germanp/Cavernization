#ifndef FIEL_H
#define FIEL_H

/**
 * @file   fiel.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:40:58 2010
 *
 * @brief <Personaje de tipo Fiel>
 *
 * @section TODO
 *  <>
 */

class Fiel: Personaje{

      public:
             /**
              * Ordena a un fiel a construir algun edificio
              * @param Edificio e
              */
             void construir(Edificio e);
             /**
              * Ordena talar un arbol para construir algun tipo de edificio
              * @param Arbol a
              */
             void talar(Arbol a);
        
}
#endif // FIEL_H
