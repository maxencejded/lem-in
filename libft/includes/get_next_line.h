/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:54:44 by mjacques          #+#    #+#             */
/*   Updated: 2018/09/20 00:20:01 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"

# define BUFF_SIZE 32
# define FDS 8192

typedef struct	s_gnl_var
{
	int			size;
	char		buff[BUFF_SIZE + 1];
	char		*pos;
	char		*tmp;
}				t_gnl_var;

int				get_next_line(const int fd, char **line);
char			*free_join(char *s1, char *s);
char			*free_append(char *s1, char s);

#endif
