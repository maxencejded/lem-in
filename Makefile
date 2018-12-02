# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 13:47:15 by mjacques          #+#    #+#              #
#    Updated: 2018/12/02 13:47:18 by mjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
RM			= rm
NAME		= lem-in
CFLAGS		= -Wall -Wextra -Werror
LIBFT 		= libft/libft.a
INCLUDES	= -I includes\
			  -I libft/includes
FUNCTIONS	=

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
