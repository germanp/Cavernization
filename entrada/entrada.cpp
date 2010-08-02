/**
 * @file   dibujar.cpp
 * @author Germán Podestá
 * @date   Sun Jun 13 12:03:40 2010
 * 
 * @brief  Este archivo tiene las rutinaas para dibujar el juego en la pantalla
 * 
 * 
 */


#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <mapa.h>
#include "entrada.h"

#define  FREC_INPUT 100 // Tiempo de refrezco 10 veces por segundo
int Entrada(void *v){
     SDL_Event evento;

		for( ; ; ) {

		while(SDL_PollEvent(&evento)) {
			if(evento.type == SDL_KEYDOWN) {
				if(evento.key.keysym.sym == SDLK_ESCAPE)
					return 0;
			}

			if(evento.type == SDL_QUIT)
				return 0;

			if(evento.type == SDL_MOUSEBUTTONDOWN) {
				printf("Antes de las declaraciones\n");
				//Cuando quiero instanciar estas cosas no pasa naranja
				/*
                Mapa& mapa = *Mapa::getInstance();
				Terreno* t = mapa(evento.button.x,evento.button.y);
				ObjetoMapa* o = t->getContenido();*/
				printf("Pase las declaraciones de los objetos\n");

				
				// boton izquierdo
				if(evento.button.button == 1){
					printf("Seleccionaste un objeto...\n");

					printf("X: %d", evento.button.x);
					printf(" - Y: %d", evento.button.y);
					printf(" Botón pulsado %d\n", evento.button.button);

					/*if ( dynamic_cast<Edificio*>(o) != NULL )
				 	{      
						printf("Selecionaste un edifcio."); 
					} 
					if ( dynamic_cast<Personaje*>(o) != NULL )
				 	{      
						printf("Selecionaste un personaje."); 
					}*/
				}
				// boton derecho
				if(evento.button.button == 3){
					printf("Seleccionaste un destino...\n");

					printf("X: %d", evento.button.x);
					printf(" - Y: %d", evento.button.y);
					printf(" Botón pulsado %d\n", evento.button.button);

					/*if ( dynamic_cast<Edificio*>(o) != NULL )
				 	{      
						printf("Selecionaste un edifcio."); 
					} 
					if ( dynamic_cast<Personaje*>(o) != NULL )
				 	{      
						printf("Selecionaste un personaje."); 
					}*/
				}

			}
		}
	}
}
/*int Entrada(void* v){
	SDL_Event evento;
	Mapa& mapa = *Mapa::getInstance();
	while (1){
		while(SDL_PollEvent(&evento)) {
			if(evento.type == SDL_KEYDOWN) {
				if(evento.key.keysym.sym == SDLK_ESCAPE)
				return 0;
			}

			if(evento.type == SDL_QUIT)
			return 0;

			if(evento.type == SDL_MOUSEBUTTONDOWN){
				
				Terreno* t = mapa(evento.button.x,evento.button.y);
				ObjetoMapa* o = t->getContenido();
				
				if ( dynamic_cast<Edificio*>(o) != NULL )
				 {      
					printf("Le pegaste a un edifcio."); 
				} 
				if ( dynamic_cast<Personaje*>(o) != NULL )
				 {      
					printf("Le pegaste a un personaje."); 
				}

				// boton izquierdo
				if(evento.button.button == 1){
					printf("Boton izquierdo...\n");
				}
				// boton derecho
				if(evento.button.button == 3){
					printf("Boton derecho...\n");
				}
			}
		}
		printf("Esperando entrada...\n");
		SDL_Delay(FREC_INPUT);
		
	}
}*/


