/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:16 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/13 01:25:34 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

UINT			ants_nbr(int fd)
{
	int		nbr;
	char	*line;

	nbr = 0;
	if (get_next_line(fd, &line) > 0 && *line)
	{
		nbr = ft_atoi(line);
		ft_strdel(&line);
	}
	return (nbr);
}

static t_flag	flag_update(char *str)
{
	t_flag	flag;

	flag = REGULAR;
	if (str[0] == COMMENT_CHAR && str[1] == COMMENT_CHAR)
	{
		if (ft_strcmp(&str[2], "start") == 0)
			flag = SOURCE;
		else if (ft_strcmp(&str[2], "end") == 0)
			flag = SINK;
	}
	return (flag);
}

t_node			*parse(int fd, t_hash **map)
{
	char		*ret;
	char		*line;
	t_node		*start;
	t_flag		flag;

	start = NULL;
	flag = REGULAR;
	while ((get_next_line(fd, &line) > 0) && *line)
	{
		ret = ft_strchr(line, '-');
		if (line[0] != COMMENT_CHAR && !ret)
		{
			if (flag == SOURCE)
				start = node_insert(line, flag, map);
			else
				node_insert(line, flag, map);
		}
		else if (line[0] != COMMENT_CHAR && ret)
			node_link(line, map, ret - line);
		flag = flag_update(line);
		free(line);
	}
	return (start);
}
