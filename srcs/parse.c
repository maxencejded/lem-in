/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:16 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/03 17:51:48 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_flag	flag_init(char *str, char *info)
{
	t_flag	flag;

	flag = REGULAR;
	if (str[0] == COMMENT && str[1] == COMMENT)
	{
		if (ft_strcmp(&str[2], "start") == 0)
		{
			flag = SOURCE;
			*info |= (*info & 1) ? 8 : 1;
		}
		else if (ft_strcmp(&str[2], "end") == 0)
		{
			flag = SINK;
			*info |= (*info & 2) ? 8 : 2;
		}
	}
	ft_strdel(&str);
	return (flag);
}

static char		*create_anthill(t_dict **map, t_node **start, char *info)
{
	int		ret;
	char	*line;
	t_flag	flags;

	flags = REGULAR;
	while ((ret = get_next_line(0, &line)) && *line && !ft_strchr(line, '-'))
	{
		if (*line != COMMENT)
		{
			if (*line == 'L')
			{
				ret = 2;
				break ;
			}
			if (node_add(map, start, line, flags) == NULL)
				return (NULL);
		}
		flags = flag_init(line, info);
	}
	if (ret == 1 && ((*info & 3) == 3))
		return (line);
	if (ret == 2)
		ft_strdel(&line);
	return (NULL);
}

static int		find_middle(char *line)
{
	char	*ret;

	ret = ft_strchr(line, '-');
	if (line[0] != COMMENT && ret)
		return (ret - line);
	return (0);
}

static void		create_link(t_dict **map, char *line)
{
	int		middle;

	if ((middle = find_middle(line)) != 0)
		node_link(map, line, middle);
	ft_strdel(&line);
	if (middle == 0)
		return ;
	while (get_next_line(0, &line) && *line)
	{
		if ((middle = find_middle(line)) != 0)
			node_link(map, line, middle);
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

t_node			*parse(t_dict **map)
{
	char	info;
	char	*line;
	t_node	*start;

	info = 0;
	start = NULL;
	line = create_anthill(map, &start, &info);
	if (!line || (info & 8))
		exit_lem_in("ERROR", map);
	create_link(map, line);
	return (start);
}
