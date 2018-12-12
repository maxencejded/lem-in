/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 21:19:04 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 15:54:35 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

static void	default_del(void *data)
{
	free(data);
}

static void	hm_item_free(void *v_item, t_hm_del_fn del)
{
	t_hm_item	*item;

	item = (t_hm_item*)v_item;
	free((void*)item->key);
	del(item->value);
	free(item);
}

void		*hm_free(t_hm *hm, t_hm_del_fn del)
{
	size_t			i;
	t_llist			*list;
	t_llist_node	*node;
	t_llist_node	*next;

	if (del == NULL)
		del = default_del;
	i = 0;
	while (i < hm->arr_size)
	{
		list = hm->keys[i];
		if (list && (node = list->first))
			while (node)
			{
				next = node->next;
				hm_item_free(node->data, del);
				free(node);
				node = next;
			}
		free(list);
		i++;
	}
	free(hm->keys);
	free(hm);
	return (NULL);
}
