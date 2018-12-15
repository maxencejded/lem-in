/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:08:00 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/14 17:32:53 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			exit_lem_in(char *str, t_hash **map)
{
	free_map(map, HASH_MAP_SIZE);
	ft_putendl(str);
	exit(-1);
}

void		free_map(t_hash **map, size_t size)
{
	size_t	i;
	t_hash	*tmp;

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

void		*free_path(t_path *path)
{
	free(path->nodes);
	free(path);
	return (NULL);
}

void		free_paths(t_paths *paths)
{
	t_paths	*cur;
	t_paths	*next;

	cur = paths;
	while (cur)
	{
		free_path(cur->path);
		next = cur->next;
		free(cur);
		cur = next;
	}
}
