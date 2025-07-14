#!/bin/bash

if [[ $1 == "--auto" ]]
then
	gcc src/*.c -o pie
	sudo mv pie /usr/local/bin/
else
	read -e -p "Compiler? " CC
	read -e -p "Install Dir? " DIR
	$CC src/*.c -o ./pie
	sudo mv pie $DIR
fi
