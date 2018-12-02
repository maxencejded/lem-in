/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:34:25 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:09:19 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*newdst;
	unsigned char	*newsrc;

	newdst = (unsigned char*)dst;
	newsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		if (newdst[i] == (unsigned char)c)
			return ((unsigned char*)(newdst + (i + 1)));
		i++;
	}
	return (NULL);
}
