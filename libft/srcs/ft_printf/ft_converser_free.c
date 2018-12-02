/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converser_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:35:27 by mjacques          #+#    #+#             */
/*   Updated: 2018/09/11 17:24:59 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*free_str(char *str, char *newstr)
{
	ft_strdel(&str);
	str = newstr;
	return (str);
}

char	*free_join(char *s1, char *s)
{
	char *tmp;

	tmp = ft_strjoin(s1, s);
	ft_strdel(&s1);
	s1 = tmp;
	return (s1);
}

char	*free_append(char *s1, char s)
{
	char *tmp;

	tmp = ft_strappend(s1, s);
	ft_strdel(&s1);
	s1 = tmp;
	return (s1);
}

char	*ft_appendwchar(char *str, wchar_t c)
{
	if (c <= 0x7f)
		str = ft_strappend(str, c);
	else if (c <= 0x7ff)
	{
		str = ft_strappend(str, (c >> 6) + 0xC0);
		str = free_append(str, (c & 0x3f) + 0x80);
	}
	else if (c <= 0xffff)
	{
		str = ft_strappend(str, (c >> 12) + 0xE0);
		str = free_append(str, (c >> 6 & 0x3F) + 0x80);
		str = free_append(str, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10ffff)
	{
		str = ft_strappend(str, (c >> 18) + 0xF0);
		str = free_append(str, ((c >> 12) & 0x3F) + 0x80);
		str = free_append(str, ((c >> 6) & 0x3F) + 0x80);
		str = free_append(str, (c & 0x3F) + 0x80);
	}
	return (str);
}

void	ft_converser_finish(char *str)
{
	g_bytes += ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}
