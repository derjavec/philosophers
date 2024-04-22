NAME		     =	pihilo
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
RM			=	rm -rf	
SRC			=	philo.c \
				utils/ft_strlen.c utils/ft_atoi.c \
				utils/ft_error.c utils/init_structures.c \
				
OBJ			=	$(SRC:.c=.o)
HEADER		= ./includes/

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)


clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re
