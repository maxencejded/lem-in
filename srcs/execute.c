/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:22:29 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 18:32:06 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		move_ants(t_path *path, int *arrived, int i, int *num)
{
	path->nodes[i + 1]->used = (num) ? *num : path->nodes[i]->used;
	ft_printf("L%d-%s ", (num) ? *num : path->nodes[i]->used,
		path->nodes[i + 1]->name);
	path->nodes[i]->used = -1;
	*arrived += (path->nodes[i + 1]->flag == SINK) ? 1 : 0;
}

static void		execute_path(t_path *path, int *arrived, int *num)
{
	int		i;

	i = path->len - 2;
	while (i >= 0)
	{
		if (path->nodes[i]->used >= 0)
			move_ants(path, arrived, i, NULL);
		i -= 1;
	}
	if (path->ants_nbr > 0)
	{
		move_ants(path, arrived, 0, num);
		*num += 1;
		path->ants_nbr -= 1;
	}
}

void			execute(t_path **path, int n_ants, int size)
{
	int		i;
	int		num;
	int		arrived;

	num = 0;
	arrived = 0;
	while (arrived != n_ants)
	{
		i = size - 1;
		while (i >= 0)
		{
			execute_path(path[i], &arrived, &num);
			i -= 1;
		}
		ft_putchar('\n');
	}
}
