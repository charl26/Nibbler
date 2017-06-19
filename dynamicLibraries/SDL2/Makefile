NAME		=	SDL2lib.so
SRC         =   SDL2lib.cpp
OBJ         =   SDL2lib.o

CC          =   clang++
CPPFLAGS    =   -fPIC -c -Wall -Werror -Wextra
LDFLAGS     =   -shared -o
RM          =   rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(CPPFLAGS)
	$(CC) $(OBJ) $(LDFLAGS) $(NAME) -I./../../graphicsLibraries/SDL2/include -framework OpenGL `sdl2-config --cflags --libs`


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all