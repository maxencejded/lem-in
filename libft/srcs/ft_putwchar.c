/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:09:19 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:10:01 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	if (c <= 0x7f)
		ft_putchar(c);
	else if (c <= 0x7ff)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3f) + 0x80);
	}
	else if (c <= 0xffff)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar((c >> 6 & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10ffff)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}
