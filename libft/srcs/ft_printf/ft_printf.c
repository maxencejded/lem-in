/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:35:27 by mjacques          #+#    #+#             */
/*   Updated: 2018/09/16 15:52:02 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	g_bytes = 0;

t_conv	g_converser[N_CONVERSER] =
{
	{'%', &ft_converser_procent},
	{'s', &ft_converser_string},
	{'S', &ft_converser_wstring},
	{'c', &ft_converser_char},
	{'C', &ft_converser_wchar},
	{'p', &ft_converser_void},
	{'i', &ft_converser_number},
	{'d', &ft_converser_number},
	{'D', &ft_converser_number},
	{'o', &ft_converser_octal},
	{'O', &ft_converser_octal},
	{'u', &ft_converser_long},
	{'U', &ft_converser_long},
	{'x', &ft_converser_hexa},
	{'X', &ft_converser_hexa}
};

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = -1;
	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			i += ft_conveser(&format[i + 1], ap);
		else
		{
			ft_putchar(format[i]);
			g_bytes++;
		}
	}
	va_end(ap);
	return (g_bytes);
}
