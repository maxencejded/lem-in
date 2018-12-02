/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 23:06:50 by mjacques          #+#    #+#             */
/*   Updated: 2018/08/12 19:11:51 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	int		i;
	size_t	size;

	size = 0;
	i = -1;
	while (str[++i])
		size = size + ft_wcharlen(str[i]);
	return (size);
}
