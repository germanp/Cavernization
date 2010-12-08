#ifndef BUILDER_H
#define BUILDER_H

#include "objetomapa.h"
#include "terreno.h"

class Builder {
public:

  virtual Terreno* crearPasto()=0;
  virtual ObjetoMapa* crearFiel(unsigned int x, unsigned int y,Terreno* t)=0;
  virtual ObjetoMapa* crearCasa(unsigned int x, unsigned int y)=0;
  
};

#endif /* BUILDER_H */
