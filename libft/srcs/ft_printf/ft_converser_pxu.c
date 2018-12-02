/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converser_pxu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 23:12:05 by mjacques          #+#    #+#             */
/*   Updated: 2018/10/28 20:43:28 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_converser_void(t_var var, va_list ap)
{
	int			len;
	char		*str;
	char		*tmp;

	str = ft_strdup("0x");
	tmp = ft_itoa_base((uint64_t)va_arg(ap, void *), 16, "0123456789abcdef");
	str = free_join(str, tmp);
	ft_strdel(&tmp);
	len = ft_strlen(str);
	if (var.width > len && !ft_strchr(var.flags, '0'))
		str = free_str(str, ft_width_string(str, var, len));
	ft_converser_finish(str);
}

static char		*ft_base_hexa(t_var var, uint64_t num)
{
	char		*str;
	char		*tmp;
	char		hex[3];
	char		*basetab;

	hex[0] = '0';
	hex[1] = (var.converser == 'X') ? 'X' : 'x';
	hex[2] = 0;
	str = (ft_strchr(var.flags, '#') && num) ? ft_strdup(hex) : ft_strnew(0);
	if (var.converser == 'X')
		basetab = ft_strdup("0123456789ABCDEF");
	else
		basetab = ft_strdup("0123456789abcdef");
	if (*var.type == 0 || ft_strchr(var.type, 'h'))
		tmp = ft_itoa_base((unsigned int)num, 16, basetab);
	else
		tmp = ft_itoa_base(num, 16, basetab);
	str = free_join(str, tmp);
	ft_strdel(&basetab);
	ft_strdel(&tmp);
	return (str);
}

void			ft_converser_hexa(t_var var, va_list ap)
{
	int			len;
	char		*str;
	uint64_t	num;

	num = (uint64_t)va_arg(ap, uint64_t);
	str = ft_base_hexa(var, num);
	len = ft_strlen(str);
	if (var.precision != -1)
		str = free_str(str, ft_precision_hex(str, var, len, num));
	if (len == 0 || (num == 0 && var.precision == -1))
		str = free_str(str, ft_strdup("0"));
	if (var.precision == 0)
		str = free_str(str, ft_strdup(""));
	len = ft_strlen(str);
	if (var.width > len)
		str = free_str(str, ft_width_int(str, var, len));
	ft_converser_finish(str);
}

void			ft_converser_octal(t_var var, va_list ap)
{
	int			len;
	char		*str;
	char		*tmp;
	int64_t		num;

	num = (int64_t)va_arg(ap, int64_t);
	str = (ft_strchr(var.flags, '#') && num) ? ft_strdup("0") : ft_strnew(0);
	tmp = ft_itoa_base(num, 8, "01234567");
	str = free_join(str, tmp);
	ft_strdel(&tmp);
	len = ft_strlen(str);
	if (var.precision != -1 && var.precision > len)
		str = free_str(str, ft_precision_int(str, var, len));
	if (num == 0 && var.precision == 0 && !ft_strchr(var.flags, '#'))
		str = free_str(str, ft_strdup(""));
	len = ft_strlen(str);
	if (var.width > len)
		str = free_str(str, ft_width_int(str, var, len));
	ft_converser_finish(str);
}

void			ft_converser_long(t_var var, va_list ap)
{
	int			len;
	char		*str;
	uint64_t	number;

	number = (uint64_t)va_arg(ap, uint64_t);
	if (*var.type == 0)
		str = ft_itoa_base_long((unsigned int)number, 10, "0123456789");
	else if (ft_strchr(var.type, 'l') || var.converser == 'U')
		str = ft_itoa_base_long((unsigned long)number, 10, "0123456789");
	else if (ft_strchr(var.type, 'j'))
		str = ft_itoa_base_long((size_t)number, 10, "0123456789");
	else
		str = ft_itoa_base_long(number, 10, "0123456789");
	if (number == 0 || *str == '\0')
		str = free_str(str, ft_strdup("0"));
	len = ft_strlen(str);
	if (var.precision != -1 && var.precision > len)
		str = free_str(str, ft_precision_int(str, var, len));
	len = ft_strlen(str);
	if (var.width > len)
		str = free_str(str, ft_width_int(str, var, len));
	ft_converser_finish(str);
}
