/**
 * @file   sprites.cpp
 * @author german <german@german-desktop>
 * @date   Mon Aug  2 16:38:31 2010
 * 
 * @brief  En este fichero se las especializaciones de SDL_Sprite de cada clase que
 * use un sprite.
 * 
 */

#ifndef SPRITES_CPP
#define SPRITES_CPP

#include "sdl_sprite.h"
#include "fiel.h"
#include "string.h"

template<> void SDL_Sprite<Fiel>::getSpriteData(struct SpriteData* data){
  const char* tmpl="fiel%1d%1d%02d.png";
  strncpy(data->tmpl,tmpl,strlen(tmpl)+1);
  data->nEstados=2;
  data->nOrientaciones=1;
  //  (data->nSprites)[0][0]=12;
  return;
}

#endif // SPRITES_CPP
