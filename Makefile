CC = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
NAME = ft_containers
RM = rm -f

.cpp.o: ft_containers
	  ${CC} ${FLAGS} -c -I. $< -o ${<:.cpp=.o}

${NAME}: ${OBJ} 
		${CC} ${FLAGS} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJ} 

fclean: clean
		${RM} ${NAME} 

re: fclean all
