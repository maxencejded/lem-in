/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:16 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/14 15:33:55 by mjacques         ###   ########.fr       */
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

static t_flag	flag_update(char *str, UINT *st)
{
	t_flag	flag;

	flag = REGULAR;
	if (str[0] == COMMENT_CHAR && str[1] == COMMENT_CHAR)
	{
		if (ft_strcmp(&str[2], "start") == 0)
		{
			flag = SOURCE;
			st[0] = st[0] << 1;
			st[0] += 1;
		}
		else if (ft_strcmp(&str[2], "end") == 0)
		{
			flag = SINK;
			st[1] = st[1] << 1;
			st[1] += 1;
		}
	}
	ft_strdel(&str);
	return (flag);
}

char			*create_anthill(int fd, t_hash **map, UINT *st, t_node **start)
{
	int		ret;
	char	*line;
	t_flag	flags;

	flags = REGULAR;
	while (((ret = get_next_line(fd, &line)) > 0) && line && *line
		&& !ft_strchr(line, '-'))
	{
		if (line[0] != COMMENT_CHAR)
		{
			if (line[0] == 'L' || !(node_insert(line, flags, map, start)))
				break ;
		}
		flags = flag_update(line, st);
	}
	if (line && !*line)
		ft_strdel(&line);
	return (line);
}

void			create_link(int fd, t_hash **map, char *line)
{
	char	*ret;

	ret = ft_strchr(line, '-');
	if (line[0] != COMMENT_CHAR && ret)
		node_link(line, map, ret - line);
	else if (line[0] != COMMENT_CHAR && !ret)
	{
		ft_strdel(&line);
		return ;
	}
	ft_strdel(&line);
	while ((get_next_line(fd, &line) > 0) && line && *line)
	{
		ret = ft_strchr(line, '-');
		if (line[0] != COMMENT_CHAR && ret)
			node_link(line, map, ret - line);
		else if (line[0] != COMMENT_CHAR && !ret)
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

t_node			*parse(int fd, t_hash **map)
{
	char	*line;
	UINT	st[2];
	t_node	*start;

	start = NULL;
	ft_bzero(st, sizeof(UINT) * 2);
	line = create_anthill(fd, map, st, &start);
	if (!line)
		exit_lem_in("ERROR", map);
	create_link(fd, map, line);
	return ((st[0] == 1 && st[1] == 1) ? start : NULL);
}
