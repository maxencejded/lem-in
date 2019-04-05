/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:08:00 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 01:18:50 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			exit_lem_in(char *str, t_dict **map)
{
	map_free(map, DICT_SIZE);
	ft_putendl(str);
	exit(-1);
}

void		map_free(t_dict **map, size_t size)
{
	size_t	i;
	t_dict	*tmp;

	if (!map)
		return ;
	i = -1;
	while (++i < size)
	{
		while (map[i])
		{
			tmp = map[i];
			map[i] = map[i]->next;
			node_free(tmp->data);
			free(tmp);
		}
	}
	free(map);
}

void		node_free(t_node *node)
{
	t_edge	*edges;
	t_edge	*tmp;

	if (!node)
		return ;
	ft_strdel(&node->name);
	edges = node->edges;
	while (edges)
	{
		tmp = edges;
		edges = edges->next;
		free(tmp);
	}
	free(node);
}

void		path_free(t_path **path, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(path[i]->nodes);
		free(path[i]);
		i += 1;
	}
	free(path);
}

void		free_paths(t_paths *paths)
{
	t_paths	*tmp;

	while (paths)
	{
		tmp = paths;
		paths = paths->next;
		free(tmp);
	}
}
