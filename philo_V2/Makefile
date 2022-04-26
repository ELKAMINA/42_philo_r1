CC = gcc -Wall -Wextra -Werror -pthread #-fsanitize=thread

NAME = philo

SRC = philo.c\
		./src/ext_func/ft_atol.c \
		./src/parsing/parsing_args.c\
		./src/creating_nodes/create_nodes.c\
		./src/protect_free/protect_destr_free.c\
		./src/ext_func/ft_lstadd_back.c \
		./src/ext_func/ft_lstnew.c\
		./src/ext_func/ft_lstlast.c \
		./src/ext_func/ft_lstclear.c \
		./src/dining_reso/dining_philos.c \
		./src/dining_reso/living/living.c \
		./src/dining_reso/createjoin_th/create_join_thr.c \
		./src/dining_reso/converting_time/sec_tomilsec.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
