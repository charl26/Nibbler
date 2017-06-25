NAME = SDL2lib.so

SRC = SDL2lib.cpp
OBJ = SDL2lib.o
CC = clang++

DLCFLAG  = -L ~/.brew/lib/ -lSDL2 -lSDL2_image -lSDL2_ttf
DLCFLAG += -framework OpenGL -framework Cocoa
DLCFLAG += -Wl,-rpath,~/.brew/lib/
CFLAG += -fPIC -c -Wall -Wextra -std=gnu++11

all: $(NAME)

$(NAME):
	@$(CC) $(SRC) $(CFLAG) -I~/.brew/include/SDL2/ -D_THREAD_SAFE
	@echo "object file created"
	@$(CC) $(OBJ) -fPIC -undefined dynamic_lookup -shared -o $(NAME) $(DLCFLAG) -g $(shell sdl2-config --cflags)
	@echo "compile shared lib"
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)
	@echo "clean complete"

fclean: clean
	@rm -f $(NAME)
	@echo "everything is now gone"

re: fclean all
