#ifndef TEMPLO_H
#define TEMPLO_H

/**
 * @file   templo.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:09:58 2010
 *
 * @brief <Edificio de tipo Templo en el cual los fieles son 
 *         entrenados hasta convertirse en predicadores.>
 *
 * @section TODO
 *  <>
 */

class Templo: Edificio{

      public:
             Predicador entrenar(Fiel f);
}
#endif // TEMPLO_H
