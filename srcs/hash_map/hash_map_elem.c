/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:38 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/02 16:07:19 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

/*
** FNV-1a for 32 bits
** FNV prime = 16777619
** FNV offset basis = 2166136261
*/

size_t			hash_fnv_onea(char *string)
{
	unsigned int	i;
	unsigned int	hash;

	hash = FNV_OFFSET_32;
	i = 0;
	while (string[i])
	{
		hash ^= string[i];
		hash *= FNV_PRIME_32;
		i += 1;
	}
	return ((size_t)hash);
}

static t_hash	*elem_create(char *key, void *data)
{
	t_hash		*new;

	if (!(new = malloc(sizeof(t_hash))))
		return (NULL);
	new->key = key;
	new->data = data;
	new->next = NULL;
	return (new);
}

void			elem_insert(t_hash **map, size_t size, char *key, void *data)
{
	t_hash			*element;
	unsigned int	hash;

	element = elem_create(key, data);
	if (element)
	{
		hash = hash_fnv_onea(key) % size;
		if (map[hash] == NULL)
			map[hash] = element;
		else
		{
			element->next = map[hash];
			map[hash] = element;
		}
	}
}

void			*elem_find(t_hash **map, size_t size, char *key)
{
	char			ret;
	t_hash			*tmp;
	unsigned int	hash;

	hash = hash_fnv_onea(key) % size;
	if (!map[hash] || map[hash]->key == NULL)
		return (NULL);
	else if (map[hash]->next == NULL)
		return (map[hash]->data);
	else
	{
		tmp = map[hash];
		while ((ret = ft_strcmp(key, tmp->key)) != 0 && tmp->next)
			tmp = tmp->next;
		return ((ret == 0) ? tmp->data : NULL);
	}
	return (NULL);
}
