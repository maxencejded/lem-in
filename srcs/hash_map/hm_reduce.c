/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_reduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:53:57 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 14:54:08 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

void	*hm_reduce(t_hm *hm, void *ctx, t_hm_reduce_fn fn)
{
	size_t			i;
	t_llist			*list;
	t_llist_node	*node;
	t_hm_item		*item;
	void			*acc;

	i = 0;
	acc = ctx;
	while (i < hm->arr_size)
	{
		list = hm->keys[i++];
		if (list)
		{
			node = list->first;
			while (node)
			{
				item = (t_hm_item*)node->data;
				acc = fn(acc, item->key, item->value);
				node = node->next;
			}
		}
	}
	return (ctx);
}
