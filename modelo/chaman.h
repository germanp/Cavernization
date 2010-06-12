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

class Chaman: Personaje{

      public:
             /**
              * Lanza un hechizo hacia una posicion.
              *
              * @param Hechizo h, int x, int y
              */
             void lanzarHechizo(Hechizo h, int x, int y);
             /**
              * Revive a un personaje.
              */
             void revivir();   
        
}
#endif // CHAMAN_H
