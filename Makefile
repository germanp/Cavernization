CPP=g++
CC=gcc
LIBS=-lSDL -lSDL_image

BIN=cavernization
INCS=-Imodelo
CFLAGS=$(INCS) -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT
CXXFLAGS=$(CFLAGS)
WINDRES=echo Que la chupe: 

# Project: cavernization
# Makefile created by Dev-C++ 4.9.9.2

OBJ  = main.o UI/input.o UI/dibujar.o modelo/terrenos.o modelo/agua.o modelo/arbol.o modelo/arbolchico.o modelo/arbolgrande.o modelo/arbolmediano.o modelo/casa.o modelo/chaman.o modelo/cuartel.o modelo/fiel.o modelo/guerrero.o modelo/guerrerofuego.o modelo/jugador.o modelo/jugadorhumano.o modelo/jugadoria.o modelo/mapa.o modelo/monumento.o modelo/personaje.o modelo/plantilla.o modelo/predicador.o modelo/tablero.o modelo/templo.o $(RES)
LINKOBJ  = main.o UI/input.o UI/dibujar.o modelo/terrenos.o modelo/agua.o modelo/arbol.o modelo/arbolchico.o modelo/arbolgrande.o modelo/arbolmediano.o modelo/casa.o modelo/chaman.o modelo/cuartel.o modelo/fiel.o modelo/guerrero.o modelo/guerrerofuego.o modelo/jugador.o modelo/jugadorhumano.o modelo/jugadoria.o modelo/mapa.o modelo/monumento.o modelo/personaje.o modelo/plantilla.o modelo/predicador.o modelo/tablero.o modelo/templo.o $(RES)
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before cavernization all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "cavernization" $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

UI/input.o: UI/input.cpp
	$(CPP) -c UI/input.cpp -o UI/input.o $(CXXFLAGS)

UI/dibujar.o: UI/dibujar.cpp
	$(CPP) -c UI/dibujar.cpp -o UI/dibujar.o $(CXXFLAGS)

modelo/terrenos.o: modelo/terrenos.cpp
	$(CPP) -c modelo/terrenos.cpp -o modelo/terrenos.o $(CXXFLAGS)

modelo/agua.o: modelo/agua.cpp
	$(CPP) -c modelo/agua.cpp -o modelo/agua.o $(CXXFLAGS)

modelo/arbol.o: modelo/arbol.cpp
	$(CPP) -c modelo/arbol.cpp -o modelo/arbol.o $(CXXFLAGS)

modelo/arbolchico.o: modelo/arbolchico.cpp
	$(CPP) -c modelo/arbolchico.cpp -o modelo/arbolchico.o $(CXXFLAGS)

modelo/arbolgrande.o: modelo/arbolgrande.cpp
	$(CPP) -c modelo/arbolgrande.cpp -o modelo/arbolgrande.o $(CXXFLAGS)

modelo/arbolmediano.o: modelo/arbolmediano.cpp
	$(CPP) -c modelo/arbolmediano.cpp -o modelo/arbolmediano.o $(CXXFLAGS)

modelo/casa.o: modelo/casa.cpp
	$(CPP) -c modelo/casa.cpp -o modelo/casa.o $(CXXFLAGS)

modelo/chaman.o: modelo/chaman.cpp
	$(CPP) -c modelo/chaman.cpp -o modelo/chaman.o $(CXXFLAGS)

modelo/cuartel.o: modelo/cuartel.cpp
	$(CPP) -c modelo/cuartel.cpp -o modelo/cuartel.o $(CXXFLAGS)

modelo/fiel.o: modelo/fiel.cpp
	$(CPP) -c modelo/fiel.cpp -o modelo/fiel.o $(CXXFLAGS)

modelo/guerrero.o: modelo/guerrero.cpp
	$(CPP) -c modelo/guerrero.cpp -o modelo/guerrero.o $(CXXFLAGS)

modelo/guerrerofuego.o: modelo/guerrerofuego.cpp
	$(CPP) -c modelo/guerrerofuego.cpp -o modelo/guerrerofuego.o $(CXXFLAGS)

modelo/jugador.o: modelo/jugador.cpp
	$(CPP) -c modelo/jugador.cpp -o modelo/jugador.o $(CXXFLAGS)

modelo/jugadorhumano.o: modelo/jugadorhumano.cpp
	$(CPP) -c modelo/jugadorhumano.cpp -o modelo/jugadorhumano.o $(CXXFLAGS)

modelo/jugadoria.o: modelo/jugadoria.cpp
	$(CPP) -c modelo/jugadoria.cpp -o modelo/jugadoria.o $(CXXFLAGS)

modelo/mapa.o: modelo/mapa.cpp
	$(CPP) -c modelo/mapa.cpp -o modelo/mapa.o $(CXXFLAGS)

modelo/monumento.o: modelo/monumento.cpp
	$(CPP) -c modelo/monumento.cpp -o modelo/monumento.o $(CXXFLAGS)

modelo/personaje.o: modelo/personaje.cpp
	$(CPP) -c modelo/personaje.cpp -o modelo/personaje.o $(CXXFLAGS)

modelo/plantilla.o: modelo/plantilla.cpp
	$(CPP) -c modelo/plantilla.cpp -o modelo/plantilla.o $(CXXFLAGS)

modelo/predicador.o: modelo/predicador.cpp
	$(CPP) -c modelo/predicador.cpp -o modelo/predicador.o $(CXXFLAGS)

modelo/tablero.o: modelo/tablero.cpp
	$(CPP) -c modelo/tablero.cpp -o modelo/tablero.o $(CXXFLAGS)

modelo/templo.o: modelo/templo.cpp
	$(CPP) -c modelo/templo.cpp -o modelo/templo.o $(CXXFLAGS)

cavernization_private.res: cavernization_private.rc 
	$(WINDRES) -i cavernization_private.rc --input-format=rc -o cavernization_private.res -O coff 
