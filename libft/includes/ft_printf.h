/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:35:27 by mjacques          #+#    #+#             */
/*   Updated: 2018/09/20 00:21:06 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

# include "libft.h"

# define CONVERSER		"sScCpidDoOuUxX%"
# define N_CONVERSER	15

typedef struct	s_var
{
	char		*flags;
	int			width;
	int			precision;
	char		*type;
	char		converser;
}				t_var;

typedef struct	s_conv
{
	char		conv;
	void		(*fct)(t_var var, va_list ap);
}				t_conv;

extern t_conv	g_converser[N_CONVERSER];
extern size_t	g_bytes;

int				ft_printf(const char *format, ...);

int				ft_conveser(const char *format, va_list	ap);
void			struct_init(t_var *var);
int				ft_check_type(const char *str, t_var *var);
int				ft_isflag(char c);
int				ft_istype(const char *str, char **type);

void			ft_converser_procent(t_var var, va_list ap);
void			ft_converser_string(t_var var, va_list ap);
void			ft_converser_wstring(t_var var, va_list ap);
void			ft_converser_char(t_var var, va_list ap);
void			ft_converser_wchar(t_var var, va_list ap);

void			ft_converser_void(t_var var, va_list ap);
void			ft_converser_hexa(t_var var, va_list ap);
void			ft_converser_octal(t_var var, va_list ap);
void			ft_converser_long(t_var var, va_list ap);

void			ft_converser_number(t_var var, va_list ap);

char			*ft_width_string(char *str, t_var var, int len);
char			*ft_width_int(char *str, t_var var, int len);
char			*number_flag(char *str, t_var var, int len);
char			*ft_itoa_base_long(uint64_t value, int base, const char *btab);

char			*ft_precision_string(char *str, t_var var);
char			*ft_precision_wstring(wchar_t *wstr, t_var var);
char			*ft_precision_int(char *str, t_var var, int len);
char			*ft_precision_hex(char *str, t_var var, int len, int number);

char			*free_str(char *str, char *newstr);
char			*free_join(char *s1, char *s);
char			*free_append(char *s1, char s);
char			*ft_appendwchar(char *str, wchar_t c);
void			ft_converser_finish(char *str);

#endif
