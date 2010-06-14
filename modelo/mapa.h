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
  int ANCHO;
  int ALTO;
  Terreno* mapa[];
  static Mapa* _instance;
  /** 
   * Carga un mapa en un vector de tipo Terreno.
   *
   * @param file Ruta del archivo de datos para cargar 
   *		(queda pendiente)
   */
  Mapa(const char*);

 public:
  inline int getAncho();
  inline int getAlto();

  static Mapa* getInstance();
  static Mapa* getInstance(const char* file);
  /** 
   * Operador [] sobrecargado para recorrer la matríz de Terreno
   * 
   * @param pos Posición del vector Terreno a devolver
   * 
   * @return La posición solicitada en la matríz.
   */
  inline Terreno* operator[](int pos);
/** 
 * Libera la memoria ocupada por el mapa que es toda
 * la información del juego.
 *
 */
  ~Mapa();
};

#endif // MAPA_H
