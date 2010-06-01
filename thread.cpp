/**
 * @file   thread.cpp
 * @author german <german@computarora>
 * @date   Sun May 30 18:46:25 2010
 * 
 * @brief  Este archivo contiene la implementación de las funciones
 * de la clase Thread
 * 
 */

#include "thread.h"
#include <SDL.h>

//Thread::Thread() {}

//void Thread::start(void* a){
void Thread::start(){
  //   setArg(a); // store user data
  thread_ = SDL_CreateThread(Thread::entryPoint,this);
   // Agregar el checkeo por NULL
   return ;
}

void Thread::setup(){}
// inline void* Thread::getArg() const {return arg_;}

// inline void Thread::setArg(void* a) {arg_ = a;}

//int Thread::run(void * arg)
int Thread::run(){
   setup();
   execute();
   //   execute( arg );
}

/*static */
int Thread::entryPoint(void* pthis)
{
   Thread* pt = (Thread*)pthis;
   return pt->run();
   //   return pt->run( pt->getArg() );
}
