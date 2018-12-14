/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:41:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/14 12:18:03 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <ft_printf.h>

t_path			*create_path(size_t size)
{
	t_path	*path;

	if ((path = (t_path*)malloc(sizeof(t_path))) == NULL)
		ft_error("not enough memory");
	if ((path->nodes = (t_node**)malloc(sizeof(t_node*) * size)) == NULL)
		ft_error("not enough memory");
	path->len = (UINT)size;
	return (path);
}

t_paths				*create_paths(t_path *path)
{
	t_paths *p;

	if ((p = (t_paths*)malloc(sizeof(t_paths))) == NULL)
		return (NULL);
	p->path = path;
	p->next = NULL;
	return (p);
}

void				print_path(t_path *path)
{
	size_t i;

	i = 0;
	while (i < path->len)
	{
		ft_printf("%s -> ", path->nodes[i]->name);
		i++;
	}
	ft_printf(" [%d]\n", path->len);
}

void				print_paths(t_paths *paths)
{
	t_paths *cur;

	cur = paths;
	while (cur)
	{
		print_path(cur->path);
		cur = cur->next;
	}
}
