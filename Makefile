# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 17:33:26 by mjacques          #+#    #+#              #
#    Updated: 2019/04/05 00:47:46 by mjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
RM			= rm -f
NAME		= lem-in
CFLAGS		= -Wall -Wextra -Werror -g
LIBFT 		= libft/libft.a
INCLUDES	= -I includes\
			  -I libft/includes

BASE		= main.c error.c print.c
PARSE		= parse.c node.c edges.c
PATH_MAP	= path.c set_path.c find_paths.c
EXECUTE		= dispatch.c execute.c
DICT		= dict_new.c dict_insert.c dict_search.c dict_free.c hash.c
QUEUE		= queue_new.c queue_free.c queue_add.c queue_pop.c

FUNCTIONS	= $(BASE) $(PARSE) $(PATH_MAP) $(EXECUTE)\
				$(addprefix queue/, $(QUEUE))\
				$(addprefix dict/, $(DICT))
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
