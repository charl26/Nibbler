#include <iostream>
#include <dlfcn.h>
#include "SFMLlib.hpp"

int main(int ac, char ** av){
	if (ac != 2){
		std::cout<<"incorrect screen dimentions (./a.out x)"<<std::endl;
	}
	else if (ac == 2){
		if (atoi(av[1]) < 10){
			std::cout<<"screen size is too sall: must be at least 10"<<std::endl;
			return 0;
		}
		else if (atoi(av[1]) > 50){
			std::cout<<"screen size is too big: max is 50"<<std::endl;
			return 0;
		}
		else {
			void *handle;


			handle = dlopen("~/SFMLlib.so", RTLD_GLOBAL);
			if (!handle) {
				std::cout << "library failed" << std::endl;
				std::cout << dlerror();
				return (0);
			} else std::cout << "library opened" << std::endl;


			create_t *create_game = (create_t *) dlsym(handle, "create");
			if (!create_game) {
				std::cout << "build is fuckedd" << std::endl;
				std::cout << dlerror();
				return (0);
			} else std::cout << "build loaded" << std::endl;

			void (*destroy)() = (void (*)()) dlsym(handle, "create");
			if (!destroy) {
				std::cout << "destroy is fuckedd" << std::endl;
				std::cout << dlerror();
				return (0);
			} else std::cout << "Destroy loaded" << std::endl;


			gameControl *new_game = create_game(atoi(av[1]));
			std::cout << "object created" << std::endl;
			std::cout << "object destroyed" << std::endl;


			dlclose(handle);
			std::cout << "library closed" << std::endl;
		}
	}
    return (0);
}