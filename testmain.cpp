//
// Created by Craig MAYO on 2017/06/20.
//

#include "./src/CoreGame.hpp"
#include "dynamicLibraries/dylib.hpp"
#include <dlfcn.h>

int main(int ac, char **av){
	if (ac == 4){
		void* handle = nullptr;
		if (atoi(av[1]) == 1){
			handle = dlopen("~/dynamicLibraries/GLFW/GLFWlib.so", RTLD_LAZY);
			std::cout<<"GLFW loaded"<<std::endl;
		}
		else if ((atoi(av[1]) == 2)){
			handle = dlopen("~/dynamicLibraries/SFML/SFMLlib.so", RTLD_LAZY);
			std::cout<<"SFML loaded"<<std::endl;
		}
		else if ((atoi(av[1]) == 3)){
			handle = dlopen("~/dynamicLibraries/SDL2/SDL2lib.so", RTLD_LAZY);
			std::cout<<"SLD2 loaded"<<std::endl;
		}
		else if ((atoi(av[1]) == 4)){
			handle = dlopen("~/dynamicLibraries/NCUR/NCURlib.so", RTLD_LAZY);
			std::cout<<"NCUR loaded"<<std::endl;
		}

		CoreGame* game = new CoreGame();
		game->setWindowHeight(atoi(av[2]));
		game->setWindowWidth(atoi(av[3]));
		if(!handle){
			std::cout<<"Library not opened : "<<dlerror()<<std::endl;
			return (0);
		}
		else std::cout<<"Library Loaded"<<std::endl;
		create_t *build = (create_t *)dlsym(handle, "create");
		if(!build){
			std::cout<<"function not opened : "<<dlerror()<<std::endl;
		}else std::cout<<"function Loaded"<<std::endl;
		build(game);
		std::cout<<"Window Loaded"<<std::endl;
		dlclose(handle);
		std::cout<<"Library Closed"<<std::endl;

		return (0);
	}
	else {
		std::cout<<"error in input"<<std::endl;
		return (0);
	}

}