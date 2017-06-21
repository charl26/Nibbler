NAME = SFMLlib.so

SRC = SFMLlib.cpp
OBJ = SFMLlib.o
CC = clang++

DLCFLAG  = -L ../../graphicsLibraries/SFML/lib/
DLCFLAG += -lsfml-system
DLCFLAG += -lsfml-network
DLCFLAG += -lsfml-window
DLCFLAG += -lsfml-graphics
DLCFLAG += -lsfml-audio
DLCFLAG += -framework OpenGL -framework Cocoa
DLCFLAG += -Wl,-rpath,../../graphicsLibrairies/SFML/lib
CFLAG += -fPIC -c -Wall -Wextra -std=gnu++11

all: $(NAME)

$(NAME):
	@$(CC) $(SRC) $(CFLAG) -I./../../graphicsLibraries/SFML/include
	@echo "object file created"
	@$(CC) $(OBJ) -fPIC -undefined dynamic_lookup  -shared -o $(NAME) $(DLCFLAG)
	@echo "compile shared lib"
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)
	@echo "clean complete"

fclean: clean
	@rm -f $(NAME)
	@echo "everything is now gone"

re: fclean all