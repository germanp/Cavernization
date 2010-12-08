BASEDIR=..
CFLAGS=$(shell sdl-config --cflags) -g
INCS=-I$(BASEDIR)/logica/ -I$(BASEDIR)/ -I$(BASEDIR)/entrada/
CXX=g++ $(CFLAGS) $(INCS)
RM=rm -f

OBJS=vista.o tiles.o sprites.o sdl_builder.o

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) -c $<

all: $(OBJS)

.PHONY: clean
clean:
	$(RM) *.a *.o *~
