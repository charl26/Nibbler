NAME		=	GLFWlib.so
SRC			=	glfw.cpp
OBJ         =   $(SRCS:.cpp=.o)

CC          =   g++
CPPFLAGS    =   -fPIC -c -Wall -Wextra
LDFLAGS     =   -shared -o
RM          =   rm -rf
GLFW        =   ../../graphicsLibraries/glfw/src/libglfw3.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -undefined dynamic_lookup $(GLFW) ${LDFLAGS} $(NAME)

clean:
	$(RM) glfw.o

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all