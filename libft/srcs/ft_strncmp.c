/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:08:41 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:11:02 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*news1;
	unsigned char	*news2;

	news1 = (unsigned char	*)s1;
	news2 = (unsigned char	*)s2;
	i = 0;
	while ((news1[i] || news2[i]) && i < n)
	{
		if (news1[i] != news2[i])
			return (news1[i] - news2[i]);
		i++;
	}
	return (0);
}
