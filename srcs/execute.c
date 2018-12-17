/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:00:42 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/17 05:39:39 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	execute_path(t_path *path, UINT *remaining,
	UINT *arrived, UINT *ant_nbr, char is_shortest_path)
{
	UINT	i;

	i = path->len - 2;
	while (i != 0)
	{
		if (path->nodes[i]->used != 0)
		{
			path->nodes[i + 1]->used = path->nodes[i]->used;
			ft_printf("L%d-%s ", path->nodes[i]->used,
				path->nodes[i + 1]->name);
			path->nodes[i]->used = 0;
			if (path->nodes[i + 1]->flag == SINK)
				*arrived += 1;
		}
		i -= 1;
	}
	if (*remaining != 0 && (is_shortest_path || *remaining >= path->len))
	{
		ft_printf("L%d-%s ", *ant_nbr, path->nodes[1]->name);
		path->nodes[1]->used = *ant_nbr;
		if (path->nodes[1]->flag == SINK)
			*arrived += 1;
		*ant_nbr += 1;
		*remaining -= 1;
	}
}

int			execute(t_paths *paths, UINT n_ants)
{
	UINT		remaining;
	UINT		arrived;
	UINT		ant_nbr;
	t_paths		*path;

	remaining = n_ants;
	arrived = 0;
	ant_nbr = 1;
	while (arrived != n_ants)
	{
		path = paths;
		while (path)
		{
			execute_path(path->path, &remaining, &arrived, &ant_nbr, path->path->len == paths->path->len);
			path = path->next;
		}
		ft_putchar('\n');
	}
	return (0);
}
