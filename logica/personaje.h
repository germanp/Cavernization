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

enum ORIENTACION {S,SE,E,NE,N,NO,O,SO};
enum ESTADO {QUIETO, CAMINANDO, ATACANDO, CONSTRUYENDO};

class Personaje : public ObjetoConDuenio{
private:
  int _caminar();
  Personaje(const Personaje& c){}
protected:
  int velocidad;
  int fuerzaGolpe;
  int destX;
  int destY;
  int alto;
  int ancho;

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
  Personaje(int x, int y);
  /** 
   * Construye el personaje pero deja las posiciones de x e y sin
   * iniciar. Obligatoriamente se debe llamar a setPos(x,y) luego de
   * la construcción usando este constructor. Se utiliza debido a que
   * la implementación de SDL_Sprite dificulta el uso de parámetros en
   * el constructor.
   * @return 
   */
  Personaje();
  virtual ~Personaje();
  /**
   * Devuelve el estado del personaje
   * @return int
   */
  int getEstado(){ return estado; }
  /**
   * Devuelve la orientacion del personaje
   * @return int
   */
  int getOrientacion(){ return orientacion; }
  /**
   * Ordena caminar al personaje hasta una posicion en el mapa
   * @param int x, int y
   */
  void caminar(int x, int y);
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
  
  int getX();
  int getY();
  int getAncho();
  int getAlto();
  
};

#endif // PERSONAJE_H
