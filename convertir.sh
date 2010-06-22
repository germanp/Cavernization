#!/bin/sh -x

vars="CPP CC WINDRES RES LIBS INCS CXXINCS BIN CXXFLAGS CFLAGS"
cp Makefile.win Makefile
for i in $vars; do
    sed "/^$i/d" -i Makefile
done
sed 's/cavernization.exe/cavernization/' -i Makefile
tmp=`tempfile`
mv Makefile $tmp

cat <<EOF > Makefile
CPP=g++
CC=gcc
LIBS=-lSDL -lSDL_image

BIN=cavernization
INCS=-Imodelo
CFLAGS=\$(INCS) `sdl-config --cflags`
CXXFLAGS=\$(CFLAGS)
WINDRES=echo Que la chupe: 

EOF

cat $tmp >> Makefile