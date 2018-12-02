/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:52:25 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:11:48 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(wchar_t c)
{
	size_t	size;

	size = 0;
	if (c <= 0x7f)
		size = 1;
	else if (c <= 0x7ff)
		size = 2;
	else if (c <= 0xffff)
		size = 3;
	else if (c <= 0x10ffff)
		size = 4;
	return (size);
}
