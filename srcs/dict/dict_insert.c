/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:35:11 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 00:51:54 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static t_dict	*dict_elem(char *key, void *data)
{
	t_dict		*i;

	if (!(i = malloc(sizeof(t_dict))))
		return (NULL);
	i->key = key;
	i->data = data;
	i->next = NULL;
	return (i);
}

void			dict_insert(t_dict **dict, size_t size, char *key, void *data)
{
	t_dict			*element;
	unsigned int	index;

	element = dict_elem(key, data);
	if (element)
	{
		index = hash(key) % size;
		if (dict[index] == NULL)
			dict[index] = element;
		else
		{
			element->next = dict[index];
			dict[index] = element;
		}
	}
}
