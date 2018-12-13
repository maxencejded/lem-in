/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:45 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/13 00:56:42 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

t_hash			**h_map_create(size_t size)
{
	t_hash		**map;

	if (!(map = ft_memalloc(sizeof(t_hash *) * size)))
		return (NULL);
	return (map);
}

void			h_map_free(t_hash **map, size_t size)
{
	size_t		i;
	t_hash		*tmp;

	if (!map)
		return ;
	i = -1;
	while (++i < size)
	{
		while (map[i])
		{
			tmp = map[i];
			map[i] = map[i]->next;
			free(tmp);
		}
	}
	free(map);
}
