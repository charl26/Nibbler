NAME		=	SDL2lib.so
SRC         =   SDL2lib.cpp ../../src/CoreGame.cpp ../../src/snake.cpp
OBJ         =   SDL2lib.o CoreGame.o snake.o

CC          =   clang++
CPPFLAGS    =   -fPIC -c -Wall -Wextra -std=gnu++11
LDFLAGS     =   -shared -std=gnu++11
RM          =   rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(CPPFLAGS)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) -I./../../graphicsLibraries/SDL2/include -framework OpenGL `sdl2-config --cflags --libs`
	@rm -f $(OBJ)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
