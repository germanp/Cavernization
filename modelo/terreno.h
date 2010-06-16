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
#include "personaje.h"
#include <list>
#include <unistd.h>


class Terreno{
 protected:
  ::std::list<ObjetoMapa*> objetosNaturales; // Lista de árboles y
				     // monumentos. Se dibujan primero.
  Edificio* e; // Si el terreno cuenta con un edificio. Se
		      // dibujan segundo
  ::std::list<Personaje*> personajes; // Lista de personajes. Se dibujan al final
 public:
  /**
   * Permite conocer si el terreno es pisable o no.
   * La clase hija implementa este método y devuelve según
   * 0 o 1 corresponda
   */ 
  virtual bool esPisable()=0;
};
#endif // TERRENO_H
