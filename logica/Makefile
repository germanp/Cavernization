OBJS=mapa.o terrenos.o arbolchico.o arbol.o arbolgrande.o arbolmediano.o casa.o chaman.o cuartel.o fiel.o guerrero.o guerrerofuego.o jugador.o jugadorhumano.o jugadoria.o mapa.o monumento.o personaje.o predicador.o templo.o terrenos.o
RM=rm -f
AR=ar -rcs

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) -c $<

all: $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)