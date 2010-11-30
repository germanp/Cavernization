#!/bin/sh

gif=$1
est=$2
or=$3

mv -v $gif fiel${est}${or}00.gif
gif2png -O fiel${est}${or}00.gif

for i in fiel${est}${or}00.p[0-9][0-9]; do
    mv -v $i `echo $i | sed "s/00.p\([0-9][0-9]\)/\1.png/"`
done
