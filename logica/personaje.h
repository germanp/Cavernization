#ifndef PERSONAJE_H
#define PERSONAJE_H

/**
 * @file   personaje.h
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:20:58 2010
 *
 * @brief <Define el comportamiento general y los distintos atributos
 *         de los personajes del juego.>
 *
 * @section TODO
 *  <>
 */
#include <SDL_thread.h>
#include "objetoconduenio.h"
#include "edificio.h"
#include "monumento.h"
#include "terreno.h"
#include "mapa.h"

enum ORIENTACION {S,SE,E,NE,N,NO,O,SO};
enum ESTADO {QUIETO, CAMINANDO, ATACANDO, CONSTRUYENDO};

class Personaje : public ObjetoConDuenio{
private:
  Terreno* casilla;
  int _caminar();
  bool desplazar();
  Personaje(const Personaje& c){}
  int velocidad;
  int fuerzaGolpe;
  int destX;
  int destY;

  ORIENTACION orientacion;
  ESTADO estado;

  SDL_Thread* thrAccion;
  static int entCaminar(void* t);
 public:
  /** 
   * Construye el personaje y lo sitúa en las coord. x e y.
   * 
   * @param x Posición x del mapa.
   * @param y Posición y del mapa.
   * 
   * @return 
   */
  Personaje(unsigned int x, unsigned int y, unsigned int ancho, unsigned int alto, unsigned int velocidad, Terreno* casilla);

  virtual ~Personaje();

  void setCasilla(Terreno* c);

  //  virtual void setPos(unsigned int x, unsigned int y){ this->x=x+ancho/2; this->y=y; }
  /**
   * Devuelve el estado del personaje
   * @return int
   */
  ESTADO getEstado(){ return estado; }
  /**
   * Devuelve la orientacion del personaje
   * @return int
   */
  int getOrientacion(){ return orientacion; }
  /**
   * Ordena caminar al personaje hasta una posicion en el mapa
   * @param int x, int y
   */
  void caminar(unsigned int x, unsigned int y);
  /**
   * Ordena atacar a un personaje
   * @param Personaje p
   */
  void atacar(Personaje p);
  /**
   * Ordena atacar a un edificio
   * @param Edificio e
   */
  void atacar(Edificio e);
  /**
   * Pone a rezarle a un monumento
   * @param Monumento m
   */
  void rezar(Monumento m);
  /**
   * Recibe un golpe
   * @param int danio
   */
  void recibirGolpe(int danio);
  /**
   * Mata al personaje
   */
  void morir();
  
  bool cambiarCasilla(Terreno* nvaCasilla);
};

#endif // PERSONAJE_H
