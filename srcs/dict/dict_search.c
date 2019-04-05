/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:38 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 00:50:27 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void			*dict_search(t_dict **dict, size_t size, char *key)
{
	char			ret;
	t_dict			*tmp;
	unsigned int	index;

	index = hash(key) % size;
	if (dict[index] == NULL || dict[index]->key == NULL)
		return (NULL);
	else if (dict[index]->next == NULL)
		return (dict[index]->data);
	else
	{
		tmp = dict[index];
		while ((ret = ft_strcmp(key, tmp->key)) && tmp->next)
			tmp = tmp->next;
		return ((ret == 0) ? tmp->data : NULL);
	}
	return (NULL);
}
