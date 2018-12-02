/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:35:27 by mjacques          #+#    #+#             */
/*   Updated: 2018/09/16 15:51:55 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_conveser(const char *format, va_list ap)
{
	int		i;
	int		j;
	t_var	var;

	j = -1;
	i = ft_check_type(format, &var);
	while (++j < N_CONVERSER)
		(g_converser[j].conv == var.converser) ?
			g_converser[j].fct(var, ap) : 0;
	ft_strdel(&var.flags);
	ft_strdel(&var.type);
	return (i);
}

void		struct_init(t_var *var)
{
	var->flags = ft_strnew(0);
	var->width = 0;
	var->precision = -1;
	var->type = ft_strnew(2);
	var->converser = 0;
}

int			ft_check_type(const char *str, t_var *var)
{
	int		i;

	i = -1;
	struct_init(var);
	while (ft_isflag(str[++i]))
		var->flags = free_append(var->flags, str[i]);
	var->width = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		var->precision = ft_atoi(&str[++i]);
		while (ft_isdigit(str[i]))
			i++;
	}
	i += ft_istype(&str[i], &var->type);
	if (ft_strchr(CONVERSER, str[i]))
		var->converser = str[i++];
	return (i);
}

int			ft_isflag(char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-' || c == '0')
		return (1);
	return (0);
}

int			ft_istype(const char *str, char **type)
{
	int		i;

	i = 0;
	if (str[i] == 'l' || str[i] == 'h' || str[i] == 'j' || str[i] == 'z')
	{
		type[0][i] = str[i];
		i++;
		if (str[i - 1] == 'l' && str[i] == 'l')
		{
			type[0][i] = str[i];
			i++;
		}
		if (str[i - 1] == 'h' && str[i] == 'h')
		{
			type[0][i] = str[i];
			i++;
		}
	}
	return (i);
}
