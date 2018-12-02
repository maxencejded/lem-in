/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converser_sc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:51:30 by mjacques          #+#    #+#             */
/*   Updated: 2018/10/28 20:47:30 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converser_procent(t_var var, va_list ap)
{
	char	*str;

	(void)ap;
	str = ft_strdup("%");
	if (var.width > 1)
		str = free_str(str, ft_width_string(str, var, 1));
	ft_converser_finish(str);
}

void	ft_converser_string(t_var var, va_list ap)
{
	int		len;
	char	*str;

	if (var.type[0] == 'l' && var.type[1] == '\0')
		ft_converser_wstring(var, ap);
	else
	{
		str = (char *)va_arg(ap, wchar_t *);
		if (!str)
			str = ft_strdup("(null)");
		else
		{
			str = ft_strdup(str);
			len = ft_strlen(str);
			if (var.precision != -1 && var.precision < len)
				str = free_str(str, ft_precision_string(str, var));
			len = ft_strlen(str);
			if (var.width > len)
				str = free_str(str, ft_width_string(str, var, len));
		}
		ft_converser_finish(str);
	}
}

void	ft_converser_wstring(t_var var, va_list ap)
{
	int		i;
	int		len;
	char	*str;
	wchar_t	*wstr;

	wstr = (wchar_t *)va_arg(ap, wchar_t *);
	if (!wstr)
		str = ft_strdup("(null)");
	else
	{
		len = ft_wstrlen(wstr);
		str = ft_strnew(len);
		i = -1;
		while (++i < len)
			str = free_str(str, ft_appendwchar(str, wstr[i]));
		str[i] = '\0';
		if (var.precision != -1 && var.precision < len)
			str = free_str(str, ft_precision_wstring(wstr, var));
		len = ft_strlen(str);
		if (var.width > len)
			str = free_str(str, ft_width_string(str, var, len));
	}
	ft_converser_finish(str);
}

void	ft_converser_char(t_var var, va_list ap)
{
	char	c;
	char	*str;

	str = NULL;
	if (var.type[0] == 'l' && var.type[1] == '\0')
		ft_converser_wchar(var, ap);
	else
	{
		if (!(c = (char)va_arg(ap, int)))
		{
			g_bytes += 1;
			ft_putchar(c);
		}
		else
		{
			str = ft_strnew(1);
			str[0] = c;
			if (var.width > 1)
				str = free_str(str, ft_width_string(str, var, 1));
			ft_converser_finish(str);
		}
	}
}

void	ft_converser_wchar(t_var var, va_list ap)
{
	int		len;
	char	*str;
	wchar_t	c;

	c = (wchar_t)va_arg(ap, wchar_t);
	len = ft_wcharlen(c);
	str = ft_strnew(len);
	str = free_str(str, ft_appendwchar(str, c));
	str[len] = '\0';
	len = ft_strlen(str);
	if (var.width > len)
		str = free_str(str, ft_width_string(str, var, len));
	ft_converser_finish(str);
}
