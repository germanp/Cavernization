CPP=g++
CC=gcc
LIBS=-lSDL -lSDL_image
BIN=cavernization
INCS=-I$(PWD)/logica -I$(PWD)/vista -I$(PWD)/entrada -I$(PWD)
CFLAGS=$(INCS) -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -g
CXXFLAGS=$(CFLAGS)
RM = rm -f
CXX = g++ $(CFLAGS) $(INCS)

all: main 

main: logica entrada vista
	$(CXX) $(LIBS) $(CFLAGS) main.cpp logica/*.o vista/*.o entrada/*.o -o $(BIN)

.PHONY: clean logica vista entrada

logica:
	make -C logica/

entrada:
	make -C entrada/

vista:
	make -C vista/

clean:
	make -C logica/ clean
	make -C entrada/ clean
	make -C vista/ clean
	${RM} $(BIN)