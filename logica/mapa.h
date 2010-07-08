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


class Mapa {
 private:
  const int ANCHO;
  const int ALTO;
  Terreno** mapa;

  /** 
   * Carga un mapa en un vector de tipo Terreno.
   *
   * @param file Ruta del archivo de datos para cargar 
   *		(queda pendiente)
   */

  // Código del Singletton
 protected:
  Mapa(Terreno** _mapa, int _ancho, int _alto);
  static Mapa* _instance;
  virtual ~Mapa();
 private:
  Mapa(const Mapa&);
  Mapa &operator=(const Mapa&);
  //

 public:
  inline int getAncho(){ return ANCHO; }
  inline int getAlto(){ return ALTO; }

  static void abrirMapa(Terreno** t, int ancho, int alto){
    _instance=new Mapa(t,ancho,alto);
  }

  /** 
   * Devuelve la instancia del Mapa del juego. Es un Singleton.
   * 
   * @return 
   */
  static Mapa* getInstance(){ return _instance; } // ¿?

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
  Terreno* _(unsigned int x,unsigned int y){ return mapa[y*ANCHO+x]; }
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
