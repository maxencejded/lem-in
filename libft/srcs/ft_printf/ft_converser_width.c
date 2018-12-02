/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converser_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:35:27 by mjacques          #+#    #+#             */
/*   Updated: 2018/09/16 15:52:01 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_width_string(char *str, t_var var, int len)
{
	int			i;
	int			j;
	char		flags;
	char		*newstr;

	i = -1;
	j = -1;
	newstr = ft_strnew(var.width);
	flags = ((ft_strchr(var.flags, '0')) ? '0' : ' ');
	if (!ft_strchr(var.flags, '-'))
	{
		while (--var.width >= len)
			newstr[++i] = flags;
	}
	while (++j < len)
		newstr[++i] = str[j];
	while (--var.width >= len)
		newstr[++i] = ' ';
	return (newstr);
}

char			*ft_width_int(char *str, t_var var, int len)
{
	int			i;
	int			j;
	int			k;
	char		flags;
	char		*newstr;

	k = 0;
	i = -1;
	j = -1;
	newstr = ft_strnew(var.width);
	flags = ((ft_strchr(var.flags, '0')) ? '0' : ' ');
	if ((str[0] == '-' || str[0] == '+' || str[0] == ' ')
		&& ft_strchr(var.flags, '0'))
		newstr[0] = str[k++];
	if (!ft_strchr(var.flags, '-'))
		while (--var.width >= len)
			newstr[++i + k] = flags;
	while (++j < len)
		newstr[++i + k] = str[j + k];
	while (--var.width >= len)
		newstr[++i + k] = ' ';
	return (newstr);
}

char			*number_flag(char *str, t_var var, int len)
{
	int			i;
	char		*newstr;

	newstr = ft_strnew(len + 1);
	if (ft_strchr(var.flags, '+'))
		newstr[0] = '+';
	else
		newstr[0] = ' ';
	i = -1;
	while (++i < len + 1)
		newstr[1 + i] = str[i];
	return (newstr);
}

char			*ft_itoa_base_long(uint64_t value, int base, const char *btab)
{
	uint64_t	nbr;
	size_t		size;
	char		*str;

	nbr = value;
	size = 1;
	while ((nbr /= base) > 0)
		size++;
	if (!(str = ft_strnew(size)))
		return (NULL);
	str = (str + size);
	nbr = value;
	*--str = btab[nbr % base];
	while ((nbr /= base) > 0)
		*--str = btab[nbr % base];
	return (str);
}
