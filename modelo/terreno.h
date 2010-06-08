#ifndef TERRENO_H
#define TERRENO_H

/**
 * @file   terreno.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief <>
 *
 * @section TODO
 *  <todo>
 */

class Terreno{
    
      private: 
              ObjetoMapa ordenObjetos[];    
      protected:
             /**
              *  
              */ 
              int getTipo(Terreno t);
             /**
              *  
              */ 
              bool esPisable();
              
             
}
#endif // TERRENO_H
