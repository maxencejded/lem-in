CC			= gcc
RM			= rm -f
NAME		= lem-in
CFLAGS		= -Wall -Wextra -Werror -g
LIBFT 		= libft/libft.a
INCLUDES	= -I includes\
			  -I libft/includes
FUNCTIONS	= main.c parse.c error.c\
				hash_map.c hash_map_elem.c\
				node.c edges.c\
				path.c set_path.c paths_free.c\
				execute.c\
				$(addprefix queue/, queue_new.c queue_free.c queue_add.c queue_pop.c) find_paths.c

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
