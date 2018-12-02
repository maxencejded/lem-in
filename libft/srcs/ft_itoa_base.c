/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:40:31 by mjacques          #+#    #+#             */
/*   Updated: 2018/09/10 02:11:24 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int64_t value, int base, const char *basetab)
{
	uint64_t	nbr;
	size_t		size;
	char		*str;

	nbr = (value < 0) ? -value : value;
	size = (value < 0 && base == 10) ? 2 : 1;
	while ((nbr /= base) > 0)
		size++;
	if (!(str = ft_strnew(size)))
		return (NULL);
	nbr = (value < 0) ? -value : value;
	str = (str + size);
	*--str = basetab[nbr % base];
	while ((nbr /= base) > 0)
		*--str = basetab[nbr % base];
	if (value < 0 && base == 10)
		*--str = '-';
	return (str);
}
