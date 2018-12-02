/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 23:54:29 by mjacques          #+#    #+#             */
/*   Updated: 2018/09/09 23:54:31 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	swap_int32(uint32_t x)
{
	x = ((x & 0x0000ffff) << 16) | ((x & 0xffff0000) >> 16);
	x = ((x & 0x00ff00ff) << 8) | ((x & 0xff00ff00) >> 8);
	return (x);
}

uint64_t	swap_int64(uint64_t x)
{
	x = ((x & 0x00000000ffffffff) << 32) | ((x & 0xffffffff00000000) >> 32);
	x = ((x & 0x0000ffff0000ffff) << 16) | ((x & 0xffff0000ffff0000) >> 16);
	x = ((x & 0x00ff00ff00ff00ff) << 8) | ((x & 0xff00ff00ff00ff00) >> 8);
	return (x);
}
