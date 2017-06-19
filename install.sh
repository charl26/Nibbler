#!/bin/sh

git submodule init ;
git submodule update ;

cmake --version;

if [[ $? == 127 ]]; then
	brew install cmake;
fi

(cd graphicsLibraries/SFML && cmake . && make);
(cd graphicsLibraries/SDL2 && cmake . && make);
(cd graphicsLibraries/glfw && cmake . && make);
