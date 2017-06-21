NAME		=	NIBBLER
SRC			=	src/*.cpp
OBJ         =   $(SRCS:.cpp=.o)

CC          =   clang++ -std=gnu++11
CPPFLAGS    =   -Wall -Wextra
RPATH       =   Wl,-rpath,graphicsLibraries/SFML/lib/
RM          =   rm -rf
INCLUDES    =   -L ./graphicsLibraries/SFML/lib/



DEPENDENCIES = ./install.sh

all: $(NAME)

$(NAME): $(OBJ)
	#$(DEPENDENCIES)
	$(CC) $(CPPFLAGS) $(SRC) $(RPATH) $(INCLUDES) -o $(NAME)
clean:
	$(RM)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all