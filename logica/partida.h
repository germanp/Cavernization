#ifndef PARTIDA_H_
#define PARTIDA_H_


#include "jugador.h"
#include "mapa.h"


class Partida {
 private:
  Jugador** jugadores;
 public:
  Partida(const char* mapFile, Builder* build, Jugador* jugHum, unsigned int nJugad=1);
  virtual ~Partida();
  
};

#endif /* PARTIDA_H_ */
