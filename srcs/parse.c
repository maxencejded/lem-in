/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:16 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/13 13:59:04 by mjacques         ###   ########.fr       */
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
	free(str);
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
		if (line[0] != COMMENT_CHAR && line[0] != ANT_CHAR)
		{
			if (!ret)
			{
				if (!(node_insert(line, flag, map, &start)))
					break ;
			}
			else
				node_link(line, map, ret - line);
		}
		flag = flag_update(line);
	}
	ft_strdel(&line);
	return (start);
}
