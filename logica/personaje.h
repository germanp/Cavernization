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

#include "objetoconduenio.h"
#include "edificio.h"
#include "monumento.h"


class Personaje:ObjetoConDuenio{
 private:
  int vida;
  /*int velocidad;
  int fuerzaGolpe;*/
 /*  /\* */
 /*   * Orientacion del personaje: 1=sur, */
 /*   * 2=norte, 3=este, 4=oeste. */
 /*   *\/ */
 /*  int orientacion; */
 /*  /\** */
 /*   * Estado del personaje: 1=quieto, 2=moviendose */
 /*   *\/ */
 /*  int estado; */
 /* public: */
 /*  /\** */
 /*   * Devuelve el estado del personaje */
 /*   * @return int */
 /*   *\/ */
 /*  int getEstado(); */
 /*  /\** */
 /*   * Devuelve la orientacion del personaje */
 /*   * @return int */
 /*   *\/ */
 /*  int getOrientacion(); */
 /*  /\** */
 /*   * Ordena caminar al personaje hasta una posicion en el mapa */
 /*   * @param int x, int y */
 /*   *\/ */
 /*  void caminar(int x, int y); */
 /*  /\** */
 /*   * Ordena atacar a un personaje */
 /*   * @param Personaje p */
 /*   *\/ */
 /*  void atacar(Personaje p); */
 /*  /\** */
 /*   * Ordena atacar a un edificio */
 /*   * @param Edificio e */
 /*   *\/ */
 /*  void atacar(Edificio e); */
 /*  /\** */
 /*   * Pone a rezarle a un monumento */
 /*   * @param Monumento m */
 /*   *\/ */
 /*  void rezar(Monumento m); */
 /*  /\** */
 /*   * Recibe un golpe */
 /*   * @param int danio */
 /*   *\/ */
 /*  void recibirGolpe(int danio); */
 /*  /\** */
 /*   * Mata al personaje */
 /*   *\/ */
 /*  void morir(); */
};

#endif // PERSONAJE_H
