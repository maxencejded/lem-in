/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:42:40 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 22:26:48 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"
#include "libft.h"

t_hm		*hm_new(size_t arr_size, t_hm_hash_fn hash_fn)
{
	t_hm	*hm;

	MCK(hm = (t_hm*)malloc(sizeof(t_hm)), NULL);
	hm->arr_size = arr_size;
	MCK(hm->keys = (t_llist**)ft_memalloc(sizeof(t_llist*) * arr_size), NULL);
	hm->hash_fn = hash_fn ? hash_fn : hash_ascii;
	hm->size = 0;
	return (hm);
}

t_hm_item	*hm_new_item(const char *key, void *value)
{
	t_hm_item	*item;

	MCK(item = (t_hm_item*)malloc(sizeof(t_hm_item)), NULL);
	item->key = key;
	item->value = value;
	return (item);
}
