#ifndef TERRENO_H
#define TERRENO_H

/**
 * @file   terreno.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Sat Jun  5 19:14:58 2010
 *
 * @brief Define el terreno sobre el cual se dispondra
 *         a los distintos personajes y el orden en que seran 
 *         dibujados.
 *
 * @section TODO
 */

#include "objetomapa.h"
#include "edificio.h"
#include <list>
#include <unistd.h>
#include "SDL_mutex.h"
#include "SDL_thread.h"


class Terreno{
 private:
  SDL_mutex* mutex;
 protected:
  /**
   * Cada terreno puede contener un ObjetoMapa, ya sea una casa,
   * personaje, árbol, etc.
   * 
   */
  ObjetoMapa* contenido;
 public:        
  int bloquear(){
    return SDL_LockMutex(mutex);
  }
  int desbloquear(){
    return SDL_UnlockMutex(mutex);
  }
  Terreno(){ 
    mutex = SDL_CreateMutex();
    contenido=NULL; 
  }
  Terreno(ObjetoMapa* o){
    this->contenido=o;
    mutex = SDL_CreateMutex();
  }
  virtual ~Terreno(){SDL_DestroyMutex(mutex);}
  /**
   * Permite conocer si el terreno es pisable o no. Por defecto se
   * fija si hay algo ubicado en el terreno.
   */ 
  virtual bool esPisable(){
    if ( contenido ) return false; else return true;
  }
  virtual bool ponerObjeto(ObjetoMapa* o){
    if ( this->contenido == NULL ) {
      this->contenido=o;
      return 1;
    } else {
      return 0;
    }
  }
  void quitarObjeto(){
    this->contenido=NULL;
  }
  ObjetoMapa* getContenido(){ return contenido; }
  
};
#endif // TERRENO_H
