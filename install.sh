#!/bin/sh

git submodule init ;
git submodule update ;

cmake --version;

if [[ $? == 127 ]]; then
	brew --version
	if [[ $? == 127 ]]; then
	sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
	fi
	brew install cmake;
fi

(cd graphicsLibraries/SFML && cmake . && make);
(cd graphicsLibraries/SDL2 && cmake . && make);
(cd graphicsLibraries/glfw && cmake . && make);

(cd dynamicLibraries/GLFW && make re);
(cd dynamicLibraries/SFML && make re);

(mv graphicsLibraries/SFML/extlibs/libs-osx/Frameworks graphicsLibraries/SFML)
