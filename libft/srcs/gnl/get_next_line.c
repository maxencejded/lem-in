/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:54:33 by mjacques          #+#    #+#             */
/*   Updated: 2018/10/28 20:44:05 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	t_gnl_var	var;
	static char *str[FDS];

	ft_memset(var.buff, 0, BUFF_SIZE);
	if (fd < 0 || fd > FDS || !line || (var.size = read(fd, var.buff, 1)) < 0)
		return (-1);
	!str[fd] ? str[fd] = ft_strnew(0) : 0;
	if (var.size == 0 && !(ft_strchr(str[fd], '\n'))
		&& ft_strlen(str[fd]) < 1)
		return (0);
	str[fd] = free_append(str[fd], var.buff[0]);
	while (!(var.pos = ft_strchr(str[fd], '\n'))
		&& (var.size = read(fd, var.buff, BUFF_SIZE)))
	{
		var.buff[var.size] = '\0';
		str[fd] = free_join(str[fd], var.buff);
	}
	var.size = (int)(var.pos - str[fd]);
	(!var.pos) ? (var.size = ft_strlen(str[fd])) : 0;
	*line = ft_strmcpy(str[fd], var.size);
	(var.pos) ? (var.size += 1) : 0;
	var.tmp = ft_strdup(&str[fd][var.size]);
	ft_strdel(&str[fd]);
	str[fd] = var.tmp;
	return (1);
}
