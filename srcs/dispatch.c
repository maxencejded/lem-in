/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:47:45 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 17:25:12 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		paths_size(t_paths *paths)
{
	int		size;

	size = 0;
	while (paths)
	{
		paths = paths->next;
		size += 1;
	}
	return (size);
}

static t_path	**paths_number(t_paths *paths, int *size)
{
	int			i;
	t_paths		*tmp;
	t_path		**used_path;

	*size = paths_size(paths);
	if ((used_path = (t_path **)malloc(sizeof(t_path *) * (*size))))
	{
		i = 0;
		tmp = paths;
		while (i < *size)
		{
			used_path[i] = tmp->path;
			tmp = tmp->next;
			i += 1;
		}
	}
	free_paths(paths);
	return ((used_path) ? used_path : NULL);
}

t_path			**dispatch(t_paths *paths, int n_ants, int *size)
{
	int		i;
	int		j;
	t_path	**paths_list;

	if (!(paths_list = paths_number(paths, size)))
		return (NULL);
	i = 0;
	while (n_ants > 0)
	{
		j = 0;
		while (j <= i && n_ants > 0)
		{
			paths_list[j]->ants_nbr += 1;
			n_ants -= 1;
			j += 1;
			if (i < *size - 1 && paths_list[i]->ants_nbr + paths_list[i]->len >
				paths_list[i + 1]->len)
				i += 1;
		}
	}
	return (paths_list);
}
