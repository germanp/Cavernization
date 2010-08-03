/**
 * @file   personaje.cpp
 * @author braian <divided-by_joy@hotmail.com>
 * @date   Tue Jun  8 19:27:58 2010
 *
 * @brief <Implementa los metodos de la clase Personaje.>
 *
 * @section TODO
 *  <>
 */

#include "personaje.h"

Personaje::Personaje(): ObjetoConDuenio(), estado(QUIETO), orientacion(S) {}

Personaje::Personaje(int x,int y) : ObjetoConDuenio(x,y), estado(QUIETO), orientacion(S) {}

void Personaje::caminar(int x, int y){
     
}

void Personaje::atacar(Personaje p){
     
     
}

void Personaje::atacar(Edificio e){
     
     
}

void Personaje::rezar(Monumento m){
     
     
}

void Personaje::recibirGolpe(int danio){
     
     
}

void Personaje::morir(){
         
}

Personaje::~Personaje(){}
