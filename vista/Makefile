BASEDIR=..
CFLAGS=$(shell sdl-config --cflags)
INCS=-I$(BASEDIR)/logica/
CXX=g++ $(CFLAGS) $(INCS)
RM=rm -f

OBJS=vista.o sdl_terrenos.o

.SUFFIXES: .o .cpp

.cpp.o:
	$(CXX) -c $<

all: $(OBJS)

.PHONY: clean
clean:
	$(RM) *.a *.o *~
