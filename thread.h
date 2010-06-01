/**
 * @file   thread.h
 * @author german <german@computarora>
 * @date   Sun May 30 18:50:15 2010
 *
 * @brief La clase Thread es un wrapper para correr
 * threads usando un objeto
 *
 */


#ifndef THREAD_H
#define THREAD_H


#include <SDL.h>
#include <SDL_thread.h>


class Thread{
 public:
  //  Thread();
  //  void start(void* arg);
  void start();
 protected:
  int run();
  //  int run(void* a);
  static int entryPoint(void*);
  virtual void setup();
  virtual void execute()=0;
/*   inline void* getArg() const; */
/*   inline void setArg(void* a); */
 private:
  SDL_Thread* thread_;
  //  void * arg_;
};

#endif // THREAD_H
