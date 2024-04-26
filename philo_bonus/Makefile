NAME		     =	philo_bonus
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
RM			=	rm -rf	
SRC			=	philo_bonus.c \
				utils_bonus/ft_strlen.c utils_bonus/ft_atoi.c \
				utils_bonus/ft_error.c utils_bonus/init.c utils_bonus/print_action.c utils_bonus/check_if_philo_died.c \
				utils_bonus/philosopher_rutine.c utils_bonus/clean_semaphores.c utils_bonus/philo_process.c \
				utils_bonus/timestamp.c \
				
OBJ			=	$(SRC:.c=.o)
HEADER		= includes_bonus/
				
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re
