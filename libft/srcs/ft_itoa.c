/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:29:43 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:08:57 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_int(int n)
{
	int		count;

	if (n < 0)
		n = n * -1;
	count = 0;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*ft_itoa_edge(int n)
{
	int		size;
	char	*str;

	size = 11;
	if (n == 0)
		size = 1;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		str[size] = '0';
	else
	{
		str[size--] = '8';
		str[0] = '-';
		n = (n / 10) * -1;
		while (n > 0)
		{
			str[size--] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = ft_size_int(n);
	if (n == -2147483648 || n == 0)
		return (ft_itoa_edge(n));
	if (n < 0)
		size++;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	str[size] = '\0';
	size--;
	while (n > 0)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}
