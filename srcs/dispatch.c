/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:47:45 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/04 18:59:46 by mjacques         ###   ########.fr       */
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
	t_paths		*cur;
	t_path		**used_path;

	*size = paths_size(paths);
	if (!(used_path = (t_path **)malloc(sizeof(t_path *) * *size)))
	{
		free_paths(paths);
		return (NULL);
	}
	i = 0;
	cur = paths;
	while (i < *size)
	{
		used_path[i] = cur->path;
		cur = cur->next;
		i += 1;
	}
	free_paths(paths);
	return (used_path);
}

static void		fill_paths(t_path **used_path, int max, int ants)
{
	int		i;

	i = 0;
	while (i < max)
	{
		used_path[i]->ants_nbr += ants;
		i += 1;
	}
}

static void		fill_path_one(t_path **used_path, int max, int *n_ants)
{
	int		i;

	i = 0;
	while (i < max)
	{
		*n_ants -= 1;
		used_path[i]->ants_nbr += 1;
		if (*n_ants == 0)
			break ;
		i = (i == max) ? 0 : i + 1;
	}
}

t_path			**dispatch(t_paths *paths, int n_ants, int *size)
{
	int		i;
	int		ants;
	t_path	**paths_list;

	if (!(paths_list = paths_number(paths, size)))
		return (NULL);
	i = 0;
	while (n_ants > 0)
	{
		if (i + 1 < *size)
		{
			ants = paths_list[i + 1]->len - paths_list[i]->len;
			if (n_ants - (ants * (i + 1)) > 0)
			{
				n_ants -= (ants * (i + 1));
				fill_paths(paths_list, i + 1, ants);
			}
			else
				fill_path_one(paths_list, i + 1, &n_ants);
		}
		else
			fill_path_one(paths_list, *size, &n_ants);
		i += 1;
	}
	return (paths_list);
}
