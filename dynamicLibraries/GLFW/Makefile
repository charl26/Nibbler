NAME		=	GLFWlib.so
SRC			=	glfw.cpp
OBJ         =   $(SRCS:.cpp=.o)

CC          =   g++
CPPFLAGS    =   -fPIC -c -Wall -Wextra
LDFLAGS     =   -shared -o
RM          =   rm -rf
GLFW        =   ../../graphicsLibraries/glfw/src/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -undefined dynamic_lookup $(GLFW) ${LDFLAGS} $(NAME) -std=gnu++11
	@rm -f $(OBJ)

clean:
	$(RM) glfw.o

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all