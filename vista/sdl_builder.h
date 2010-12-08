#ifndef SDL_BUILDER_H
#define SDL_BUILDER_H

#include "builder.h"

#include "sdl_sprite.h"
#include "sdl_tile.h"
#include "terrenos.cpp"
#include "objetomapa.h"
#include "fiel.h"
#include "casa.h"


class SDL_Builder : public Builder {
public:
  SDL_Builder();
  Terreno* crearPasto();
  ObjetoMapa* crearFiel(unsigned int x, unsigned int y, Terreno* t);
  ObjetoMapa* crearCasa(unsigned int x, unsigned int y);
};

#endif /* SDL_BUILDER_H */
