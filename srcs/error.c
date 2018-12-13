/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:08:00 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/13 14:35:03 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			exit_lem_in(char *str, t_hash **map)
{
	free_map(map, HASH_MAP_SIZE);
	ft_putendl(str);
	exit(-1);
}

void		free_map(t_hash **map, size_t size)
{
	size_t	i;
	t_hash	*tmp;

	if (!map)
		return ;
	i = -1;
	while (++i < size)
	{
		while (map[i])
		{
			tmp = map[i];
			map[i] = map[i]->next;
			node_free(tmp->data);
			free(tmp);
		}
	}
	free(map);
}

void		node_print(t_node *node)
{
	t_edge	*tmp;

	if (!node)
		return ;
	ft_printf("\033[92m%-8s\033[0m", node->name);
	if (node->flag == SOURCE)
		ft_putstr(" | SOURCE");
	else if (node->flag == SINK)
		ft_putstr(" | SINK");
	ft_putchar('\n');
	tmp = node->edges;
	if (tmp)
		ft_printf("\t");
	while (tmp)
	{
		ft_printf(" -> \033[31m%s\033[0m%c", tmp->node->name,
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
			(map[i]) ? ft_printf("%3zu -> ", i) : 0;
			tmp = map[i];
			while (tmp)
			{
				(on) ? ft_printf("   -> ") : 0;
				node_print(tmp->data);
				tmp = tmp->next;
				on = 1;
			}
		}
	}
}
