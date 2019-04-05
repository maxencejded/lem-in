/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:41:44 by tkobb             #+#    #+#             */
/*   Updated: 2019/04/04 18:22:23 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			*create_path(size_t size)
{
	t_path	*path;

	if ((path = (t_path*)malloc(sizeof(t_path))) == NULL)
		ft_error("Not enough Memory");
	if ((path->nodes = (t_node**)malloc(sizeof(t_node*) * size)) == NULL)
		ft_error("Not enough Memory");
	path->len = (UINT)size;
	path->ants_nbr = 0;
	return (path);
}

t_paths			*create_paths(t_path *path)
{
	t_paths *p;

	if ((p = (t_paths*)malloc(sizeof(t_paths))) == NULL)
		return (NULL);
	p->path = path;
	p->next = NULL;
	return (p);
}
