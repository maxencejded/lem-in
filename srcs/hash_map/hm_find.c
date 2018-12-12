/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 21:34:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 14:20:35 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"
#include "linked_list.h"
#include "libft.h"

static int	cmp_item(void *v_key, void *v_item)
{
	const char	*key;
	t_hm_item	*item;

	key = (const char *)v_key;
	item = (t_hm_item*)v_item;
	return (ft_strcmp(key, item->key) == 0);
}

void		*hm_find(t_hm *hm, const char *key)
{
	int				index;
	t_llist			*item_container;
	t_llist_node	*node;
	t_hm_item		*item;

	VALIDATE_HASH(index = hm->hash_fn(key) % hm->arr_size, NULL);
	item_container = hm->keys[index];
	MCK(node = llist_find(item_container, (char*)key, cmp_item), NULL);
	item = (t_hm_item*)node->data;
	return (item ? item->value : NULL);
}
