/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:33:54 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:09:34 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*newdst;
	unsigned char	*newsrc;

	newdst = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	if (newsrc < newdst)
	{
		while (len--)
			newdst[len] = newsrc[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
