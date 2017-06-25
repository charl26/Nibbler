#!/bin/sh

git submodule init ;
git submodule update ;

brew --version;

if [[ $? == 127 ]]; then
	sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
fi

cmake --version;

if [[ $? == 127 ]]; then
	brew install cmake;
fi

sdl-config --cflags;

if [[ $? == 127 ]]; then
	brew install sdl2;
	brew link sdl2;
	brew install sdl2_image;
	brew install sdl2_ttf;
fi

(cd graphicsLibraries/SFML && cmake . && make);
(cd graphicsLibraries/glfw && cmake . && make);
(cd dynamicLibraries/GLFW && make re);
(cd dynamicLibraries/SFML && make re);
(mv graphicsLibraries/SFML/extlibs/libs-osx/Frameworks graphicsLibraries/SFML)
