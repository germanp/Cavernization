#ifndef TERRENO_H
#define TERRENO_H

/**
 * @file   terreno.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief <Define el terreno sobre el cual se dispondra
 *         a los distintos personajes y el orden en que seran 
 *         dibujados.>
 *
 * @section TODO
 *  <>
 */

class Terreno{
    
      private:
              /**
               * Guarda el orden en que seran dibujados los objetos 
               * sobre el terreno.
               *
               * @return ObjetoMapa 
               */
              ObjetoMapa ordenObjetos[];  
                
      protected:
             /**
              * Devuelve el tipo del terreno, ya sea 1=tierra; 
              * 2=desierto; y 3=agua.
              *
              * @param Terreno t
              * @return int
              */ 
              int getTipo(Terreno t);
             /**
              * Permite conocer si el terreno es pisable o no 
              * (en el caso de que el terreno sea de tipo agua
              * devuelve false).
              *
              * @return bool 
              */ 
              bool esPisable();
}
#endif // TERRENO_H
