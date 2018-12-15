/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:41:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/14 17:52:14 by mjacques         ###   ########.fr       */
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
