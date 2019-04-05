/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 00:44:00 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 00:44:33 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/*
** FNV-1a for 32 bits
** FNV prime = 16777619
** FNV offset basis = 2166136261
*/

size_t			hash(char *str)
{
	unsigned int	i;
	unsigned int	hash;

	hash = FNV_OFFSET_32;
	i = 0;
	while (str[i])
	{
		hash ^= str[i];
		hash *= FNV_PRIME_32;
		i += 1;
	}
	return ((size_t)hash);
}
