/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:54 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 00:46:28 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "libft.h"

# define FNV_OFFSET_32 2166136261
# define FNV_PRIME_32 16777619

typedef struct		s_dict
{
	char			*key;
	void			*data;
	struct s_dict	*next;
}					t_dict;

t_dict				**dict_init(size_t size);
void				dict_free(t_dict **dict, size_t size);
size_t				hash(char *str);
void				dict_insert(t_dict **dict, size_t size,
						char *key, void *data);
void				*dict_search(t_dict **dict, size_t size, char *key);
#endif
