/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:04:50 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/12 21:05:41 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SPACE(x) (ISSPACE(x) || ISSPACE2(x))

static size_t	ft_wordnbr(char *str)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = -1;
	while (str[++i])
	{
		if (i == 0 && !SPACE(str[i]))
			size += 1;
		else if (!SPACE(str[i]) && SPACE(str[i - 1]))
			size += 1;
	}
	return (size);
}

static size_t	ft_wordlen(char *str)
{
	size_t	size;

	size = 0;
	while (str[size] && !SPACE(str[size]))
		size++;
	return (size);
}

char			**ft_splitspace(char *str)
{
	size_t	i;
	size_t	len;
	size_t	size;
	char	**tab;

	size = ft_wordnbr(str);
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*str && SPACE(*str))
			str++;
		len = ft_wordlen(str);
		tab[i] = ft_strsub(str, 0, len);
		str += len;
	}
	tab[i] = 0;
	return (tab);
}
