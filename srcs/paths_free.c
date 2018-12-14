/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:09:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/13 21:22:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*path_free(t_path *path)
{
	free(path->nodes);
	free(path);
	return (NULL);
}

void	paths_free(t_paths *paths)
{
	t_paths	*cur;
	t_paths	*next;

	cur = paths;
	while (cur)
	{
		path_free(cur->path);
		next = cur->next;
		free(cur);
		cur = next;
	}
}
