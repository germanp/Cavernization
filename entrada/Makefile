BASE_DIR=..

CFLAGS=$(shell sdl-config --cflags)
INCS=-I$(BASE_DIR)/logica -I$(BASE_DIR)/vista
CXX=g++ $(CFLAGS) $(INCS)
RM=rm -f
AR=ar -rcs

OBJS=sdl_jugador.o

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) -c $<

all: $(OBJS) entrada.a

entrada.a:
	$(AR) $@ $(OBJS)

.PHONY: clean
clean:
	$(RM) *.a *.o *~
