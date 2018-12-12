CC			= gcc
RM			= rm -f
NAME		= lem-in
CFLAGS		= -Wall -Wextra -Werror -g
LIBFT 		= libft/libft.a
INCLUDES	= -I includes\
			  -I libft/includes
FUNCTIONS	= main.c

FILES		= $(addprefix srcs/, $(FUNCTIONS))
OBJECTS		= $(FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJECTS) $(LIBFT)

clean:
	@$(RM) $(OBJECTS)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

re: fclean all
