/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:43:15 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 00:43:18 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void			dict_free(t_dict **dict, size_t size)
{
	size_t		i;
	t_dict		*tmp;

	if (!dict)
		return ;
	i = -1;
	while (++i < size)
	{
		while (dict[i])
		{
			tmp = dict[i];
			dict[i] = dict[i]->next;
			free(tmp);
		}
	}
	free(dict);
}
