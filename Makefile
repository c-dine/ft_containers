CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp is_integral.hpp
OBJ = ${SRC:.cpp=.o}
NAME = ft_containers
RM = rm -f

.cpp.o: ft_containers
	  ${CC} ${FLAGS} -c -I. $< -o ${<:.cpp=.o}

${NAME}: ${OBJ} mlx
		${CC} ${FLAGS} ${OBJ} -I ./map/ ./stack/ ./vector/ -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJ} 

fclean: clean
		${RM} ${NAME} 

re: fclean all
