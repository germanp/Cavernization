/***************************************************************************
 Ejemplo6_1
 (C) 2003 by Alberto Garcia Serrano
 Programación de videojuegos con SDL
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "csprite.h"


// Mapa de tiles 
// cada tile tiene 64x64 píxeles
// una pantalla tiene 10x10 tiles
int mapa[100]= {0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,2,0,0,0,0,
				0,0,1,0,0,0,0,1,0,0,
				2,0,0,0,0,0,0,0,0,0,
				0,0,0,0,1,0,0,0,2,0,
				0,0,0,0,0,0,0,0,0,0,
				0,2,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,1,0,0,
				0,0,1,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0};

SDL_Surface *screen;

CFrame tile1;
CFrame tile2;
CFrame tile3;
CSprite suelo[3];
SDL_Rect rectangulo;

int done=0;


// Dibuja los esprites en la pantalla
void DrawScene(SDL_Surface *screen) {
 int i,j,x,y,t;

	//dibujar escenario
	for (i=0 ; i<10 ; i++) {
		for (j=0 ; j<10 ; j++) {
			t=mapa[i*10+j];
			// calculo de la posición del tile
			x=j*64;
			y=(i-1)*64;
			
			// dibujamos el tile
			suelo[t].setx(x);
			suelo[t].sety(y);
			suelo[t].draw(screen);
		}
	}


	// Mostramos todo el frame
	SDL_Flip(screen);
}

void finaliza() {

	// finalizamos los sprites
	suelo[0].finalize();
	suelo[1].finalize();
	suelo[2].finalize();

	}


// Preparamos los esprites
int InitSprites() {

	tile1.load("tile0.bmp");
	suelo[0].addframe(tile1);

	tile2.load("tile1.bmp");
	suelo[1].addframe(tile2);

	tile3.load("tile2.bmp");
	suelo[2].addframe(tile3);

	return 0;
}



int main(int argc, char *argv[]) {

SDL_Event event;
Uint8 *keys;


	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("No se pudo iniciar SDL: %s\n",SDL_GetError());
		return 1;
	}

	screen = SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);
	if (screen == NULL) {
		printf("No se puede inicializar el modo gráfico: \n",SDL_GetError());
		return 1;
	}

	atexit(SDL_Quit);

	InitSprites();
	
	while (done == 0) {
		
		// dibujamos el frame
		DrawScene(screen);

		// consultamos el estado del teclado
		keys=SDL_GetKeyState(NULL);

		// consultamos el estado 
		while (SDL_PollEvent(&event)) {
					
			if (event.type == SDL_QUIT) {done=1;}
					
			if (event.type == SDL_KEYDOWN)  {
						
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					done=1;
				} 
					
			}
									
		}
	}
			

	finaliza();

	return 0;
}
