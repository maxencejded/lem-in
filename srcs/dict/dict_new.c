/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:45 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 00:45:06 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict			**dict_init(size_t size)
{
	t_dict		**dict;

	if (!(dict = ft_memalloc(sizeof(t_dict *) * size)))
		return (NULL);
	return (dict);
}
