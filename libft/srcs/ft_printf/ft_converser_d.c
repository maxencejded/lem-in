/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converser_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:35:27 by mjacques          #+#    #+#             */
/*   Updated: 2018/10/28 20:41:31 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*number_dispatch(t_var var, va_list ap)
{
	char	*str;

	if (ft_strchr(var.type, 'l') || ft_strchr(var.type, 'j')
		|| var.converser == 'D')
		str = ft_itoa_base((int64_t)va_arg(ap, int64_t), 10, "0123456789");
	else if (ft_strcmp(var.type, "hh") == 0)
		str = ft_itoa_base((signed char)va_arg(ap, int64_t), 10, "0123456789");
	else if (ft_strchr(var.type, 'h'))
		str = ft_itoa_base((short)va_arg(ap, int64_t), 10, "0123456789");
	else if (ft_strchr(var.type, 'z'))
		str = ft_itoa_base((size_t)va_arg(ap, size_t), 10, "0123456789");
	else
		str = ft_itoa_base((int)va_arg(ap, int), 10, "0123456789");
	return (str);
}

static void	remove_flags(t_var var)
{
	int		i;

	i = -1;
	while (var.flags[++i])
	{
		if (var.flags[i] == '0')
			var.flags[i] = '1';
	}
}

void		ft_converser_number(t_var var, va_list ap)
{
	int		len;
	char	*str;

	str = number_dispatch(var, ap);
	len = ft_strlen(str);
	if (var.precision != -1 && var.precision > len)
		str = free_str(str, ft_precision_int(str, var, len));
	(var.precision != -1 && var.precision < var.width) ? remove_flags(var) : 0;
	len = ft_strlen(str);
	if ((ft_strchr(var.flags, ' ') || (ft_strchr(var.flags, '+')))
		&& ft_strchr(str, '-') == NULL)
		str = free_str(str, number_flag(str, var, len));
	if (var.precision == 0 && ft_atoi(str) == 0)
		str = free_str(str, ft_strdup(""));
	len = ft_strlen(str);
	if (var.width > len)
		str = free_str(str, ft_width_int(str, var, len));
	ft_converser_finish(str);
}
