# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:32:00 by mjacques          #+#    #+#              #
#    Updated: 2018/12/12 21:08:05 by mjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
RM			= rm -rf
NAMELIB		= libft.a
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I includes/

IS			= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
STRUCT		= ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c\
			  ft_lstnew.c
MEMORY		= ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memcpy.c ft_memcmp.c\
			  ft_memchr.c ft_memdel.c ft_memmove.c ft_memset.c
NUMBER		= ft_atoi.c ft_itoa.c ft_itoa_base.c ft_int_swap.c
PRINT		= ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c\
			  ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c\
			  ft_putwchar.c ft_putwstr.c
STRING		= ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
			  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
			  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
			  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c\
			  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
			  ft_strtrim.c ft_strappend.c ft_strmcpy.c ft_wstrlen.c\
			  ft_splitspace.c ft_ptrdel.c
CHAR		= ft_tolower.c ft_toupper.c ft_wcharlen.c

GNL			= get_next_line.c

PRINTF		= ft_printf.c ft_arguments.c\
			  ft_converser_sc.c ft_converser_pxu.c ft_converser_d.c\
			  ft_converser_free.c ft_converser_width.c ft_converser_precision.c

OTHER		= ft_error.c

FUNCTIONS	= $(IS) $(STRUCT) $(MEMORY) $(NUMBER) $(PRINT) $(STRING) $(CHAR) $(OTHER)

FILES		= $(addprefix srcs/, $(FUNCTIONS))\
			  $(addprefix srcs/, $(addprefix gnl/, $(GNL)))\
			  $(addprefix srcs/, $(addprefix ft_printf/, $(PRINTF)))

OBJECTS		= $(FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAMELIB)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAMELIB): $(OBJECTS)
	@ar rc $(NAMELIB) $(OBJECTS)
	@ranlib $(NAMELIB)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAMELIB)

re: fclean all
