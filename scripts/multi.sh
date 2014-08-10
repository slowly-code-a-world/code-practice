#!/bin/bash

if [ "$1" == " " ]; then
  echo "Usage: multi number"
  exit
fi
x=1

while [ $x -le $1 ]
do
	y=1
	while [ $y -le $1 ]
	do
		echo -e `expr $x \* $y` "	\c"
		y=`expr $y + 1`
	done
	echo 
	x=`expr $x + 1`
done
