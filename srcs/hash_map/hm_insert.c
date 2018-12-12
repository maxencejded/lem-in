/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 21:20:40 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 14:19:22 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"
#include "libft.h"

int		hm_insert(t_hm *hm, const char *key, void *value)
{
	int			index;
	t_hm_item	*item;

	VALIDATE_HASH(index = hm->hash_fn(key) % hm->arr_size, 1);
	MCK(item = hm_new_item(key, value), 1);
	llist_push(&hm->keys[index], (void*)item);
	hm->size++;
	return (0);
}
