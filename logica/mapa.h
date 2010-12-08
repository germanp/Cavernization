/**
 * @file   mapa.h
 * @author Germán Podestá
 * @date   Fri Jun 11 23:06:36 2010
 * 
 * @brief  Este archivo contiene la clase Mapa que es un singleton con
 * un array de Terrenos.	   
 * 
 */

#ifndef MAPA_H
#define MAPA_H

#include "terreno.h"
#include "builder.h"
#include "objetomapa.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

class Mapa {
 protected:
  const int ANCHO;
  const int ALTO;
  const int LONGCASILLA;
  Terreno** mapa;
  Builder* build;
  Mapa(Terreno**,Builder*,unsigned int, unsigned int, unsigned int);
  virtual ~Mapa();
  static Mapa* _instance;
 private:
  Mapa(const Mapa&);
  Mapa& operator=(const Mapa&);
 public:
  int getAncho(){ return ANCHO; }
  int getAlto(){ return ALTO; }
  int getLongCasilla(){ return LONGCASILLA; }
  static int cargarMapa(const char*,Builder*);
  virtual void liberarMapa();

  /**
   * Devuelve la instancia del Mapa del juego. Es un Singleton.
   *
   * @return
   */
  static Mapa* getInstance(){ return _instance; }

  /** 
   * Devuelve la posición del mapa especificada por x e y.
   * Esta es la versión para usar cuando guardamos el mapa en un
   * puntero. Ej: 
   *	Mapa* m=Mapa::getInstance();
   *	m->_(x,y);
   * 
   * @param x Coord. x del mapa
   * @param y Coord. y del mapa
   * 
   * @return 
   */  
  Terreno* _(unsigned int x,unsigned int y){
    return mapa[y*ANCHO+x];
  }
  /** 
   * Devuelve el Terreno correspondiente a la posición del mapa dada
   * por x e y. Esta es la versión de paréntesis sobrecargada. Ej:
   *	Mapa& m=*Mapa::getInstance();
   *	m(x,y);
   *
   * @param x Coord. x del mapa
   * @param y Coord. y del mapa
   * @return 
   */
  Terreno* operator() (unsigned int x, unsigned int y){ return mapa[y*ANCHO+x]; }
};

#endif // MAPA_H
