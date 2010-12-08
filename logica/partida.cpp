#include "partida.h"

Partida::Partida(const char* mapFile, Builder* build, Jugador* jugHum, unsigned int nJugad){
  if ( !Mapa::cargarMapa(mapFile,build) ) {
    throw 0;
  }
  jugadores=new Jugador*[nJugad];
  jugadores[0]=jugHum;
}

Partida::~Partida(){
  delete[] jugadores;
}
