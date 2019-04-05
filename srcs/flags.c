/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:54:57 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 13:08:59 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	flags_add(char *str, unsigned char *flags)
{
	int i;

	i = 0;
	while (str[++i])
	{
		if (str[1] == '-' && !str[2])
			return (0);
		else if (ft_strchr(FLAGS, str[i]))
		{
			if (str[i] == 'p')
				*flags |= FLAG_P;
			else if (str[i] == 'q')
				*flags |= FLAG_Q;
		}
		else
			return (-i);
	}
	return (1);
}

void		flags(int ac, char **av, unsigned char *flags)
{
	int		ret;

	ret = 1;
	ac = 1;
	while (av[ac] && av[ac][0] == '-' && av[ac][1])
	{
		ret = flags_add(av[ac], flags);
		if (ret < 0)
		{
			ft_printf("lem-in: illegal option -- %c\n", av[ac][-ret]);
			ft_error("Usage: lem-in [-apq] [file ...]");
		}
		else if (ret == 0)
			break ;
		ac += 1;
	}
}
