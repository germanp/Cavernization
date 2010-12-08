INCS=-I ../
CFLAGS=$(shell sdl-config --cflags) -g
CXX=g++ $(CFLAGS) $(INCS)

OBJS=mapa.o arbolchico.o arbol.o arbolgrande.o arbolmediano.o casa.o chaman.o cuartel.o fiel.o guerrero.o guerrerofuego.o jugador.o jugadoria.o mapa.o monumento.o personaje.o predicador.o templo.o objetomapa.o objetoconduenio.o partida.o
RM=rm -f

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) -c $<

all: $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)