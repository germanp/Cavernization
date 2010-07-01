#ifndef CHAMAN_H
#define CHAMAN_H

/**
 * @file   chaman.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:44:58 2010
 *
 * @brief <Personaje de tipo Chaman, puede lanzar hechizos contra 
 *         el bando rival y revivir a sus subordinados.>
 *
 * @section TODO
 *  <>
 */

#include "personaje.h"

class Chaman: Personaje{

      public:
             /**
              * Lanza un hechizo hacia una posicion.
              *
              * @param Hechizo h, int x, int y
              */
  //             void lanzarHechizo(Hechizo h, int x, int y);
             /**
              * Braian es un gorila
              */
             void revivir();   
        
};
#endif // CHAMAN_H
