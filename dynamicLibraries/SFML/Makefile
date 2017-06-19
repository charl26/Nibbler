NAME = SFMLlib.so

SRC = SFMLlib.cpp
OBJ = SFMLlib.o
CC = clang++

DLCFLAG  = -L./../../graphicsLibraries/SFML/lib
DLCFLAG += -lsfml-window
DLCFLAG += -lsfml-system
CFLAG += -fPIC -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@$(SET_INC_PATH)
	@echo "Path set 1"
	@$(SET_LIB_PATH)
	@echo "Path set 2"
	@$(CC) $(SRC) $(CFLAG) -I./../../graphicsLibraries/SFML/include
	@echo "object file created"
	@$(CC) $(OBJ) -shared -o $(NAME) $(DLCFLAG)
	@echo "compile shared lib"

clean:
	@rm -f $(OBJ)
	@echo "clean complete"

fclean: clean
	@rm -f $(NAME)
	@echo "everything is now gone"
		

re: fclean all