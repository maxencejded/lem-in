/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:25:37 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/14 17:51:32 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		node_print(t_node *node)
{
	t_edge	*tmp;

	if (!node)
		return ;
	ft_printf("\033[92m%-8s\033[0m", node->name);
	if (node->flag == SOURCE)
		ft_putstr("(Start) ");
	else if (node->flag == SINK)
		ft_putstr("(End)   ");
	else
		ft_putstr("        ");
	tmp = node->edges;
	while (tmp)
	{
		ft_printf("-> \033[31m%s\033[0m%c", tmp->node->name,
			(tmp->next) ? '\t' : '\n');
		tmp = tmp->next;
	}
}

void		h_map_print(t_hash **map, size_t size)
{
	size_t	i;
	int		on;
	t_hash	*tmp;

	if (map)
	{
		i = -1;
		while (++i < size)
		{
			on = 0;
			tmp = map[i];
			while (tmp)
			{
				node_print(tmp->data);
				tmp = tmp->next;
				on = 1;
			}
		}
	}
	ft_putchar('\n');
}

void		print_path(t_path *path)
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

void		print_paths(t_paths *paths)
{
	t_paths *cur;

	cur = paths;
	while (cur)
	{
		print_path(cur->path);
		cur = cur->next;
	}
}
