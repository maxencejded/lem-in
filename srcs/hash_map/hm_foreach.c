/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:44:17 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 14:53:53 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

void	hm_foreach(t_hm *hm, void *ctx, t_hm_foreach_fn fn)
{
	size_t			i;
	t_llist			*list;
	t_llist_node	*node;
	t_hm_item		*item;

	i = 0;
	while (i < hm->arr_size)
	{
		list = hm->keys[i++];
		if (list)
		{
			node = list->first;
			while (node)
			{
				item = (t_hm_item*)node->data;
				fn(ctx, item->key, item->value);
				node = node->next;
			}
		}
	}
}
