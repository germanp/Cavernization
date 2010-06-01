#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "thread.h"

class Personaje:public Thread{
 private:
  int vida;
  
 protected:
  void execute();
 public:
  Personaje(int);
  void setDanio(int d);
};

#endif // PERSONAJE_H
