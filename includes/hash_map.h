/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:54 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/02 16:05:39 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H

# include "libft.h"

# define FNV_OFFSET_32 2166136261
# define FNV_PRIME_32 16777619

typedef struct		s_hash
{
	char			*key;
	void			*data;
	struct s_hash	*next;
}					t_hash;

t_hash				**h_map_create(size_t size);
void				h_map_free(t_hash **table, size_t size);
size_t				hash_fnv_onea(char *key);
void				elem_insert(t_hash **table, size_t size,
						char *key, void *data);
void				*elem_find(t_hash **table, size_t size, char *key);
#endif
