/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:22:29 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/04 20:38:06 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	execute_path(t_path *path, int *arrived, UINT *number)
{
	int		i;

	i = path->len - 2;
	while (i >= 0)
	{
		if (path->nodes[i]->used >= 0)
		{
			path->nodes[i + 1]->used = path->nodes[i]->used;
			ft_printf("L%d-%s ", path->nodes[i]->used,
				path->nodes[i + 1]->name);
			path->nodes[i]->used = -1;
			if (path->nodes[i + 1]->flag == SINK)
				*arrived += 1;
		}
		i -= 1;
	}
	if (path->ants_nbr > 0)
	{
		ft_printf("L%d-%s ", *number, path->nodes[1]->name);
		path->nodes[1]->used = *number;
		if (path->nodes[1]->flag == SINK)
			*arrived += 1;
		*number += 1;
		path->ants_nbr -= 1;
	}
}

void		execute(t_path **path, int n_ants, int size)
{
	int		i;
	int		arrived;
	UINT	number;

	number = 0;
	arrived = 0;
	while (arrived != n_ants)
	{
		i = size - 1;
		while (i >= 0)
		{
			execute_path(path[i], &arrived, &number);
			i -= 1;
		}
		ft_putchar('\n');
	}
}
