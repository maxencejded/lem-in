/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:12 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/13 01:27:22 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*node_create(char *name)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->name = ft_strdup(name);
	new->visited = FALSE;
	new->height = 0;
	new->flag = REGULAR;
	new->edges = NULL;
	return (new);
}

void		node_free(t_node *node)
{
	t_edge	*edges;
	t_edge	*tmp;

	ft_strdel(&node->name);
	edges = node->edges;
	while (edges)
	{
		tmp = edges;
		edges = edges->next;
		free(tmp);
	}
	free(node);
}

t_node		*node_insert(char *str, t_flag flag, t_hash **map)
{
	char	**split;
	t_node	*node;

	if (!(split = ft_splitspace(str)))
		exit_lem_in(map);
	if (split[1] == NULL)
	{
		ft_ptrdel(split);
		exit_lem_in(map);
	}
	node = node_create(split[0]);
	ft_ptrdel(split);
	node->flag = flag;
	elem_insert(map, HASH_MAP_SIZE, node->name, node);
	return (node);
}

void		node_link(char *str, t_hash **map, int position)
{
	char	*node_1;
	char	*node_2;
	t_node	*elem_1;
	t_node	*elem_2;

	node_1 = ft_strsub(str, 0, position);
	node_2 = ft_strsub(str, position + 1, ft_strlen(str) - position - 1);
	elem_1 = (t_node *)elem_find(map, HASH_MAP_SIZE, node_1);
	elem_2 = (t_node *)elem_find(map, HASH_MAP_SIZE, node_2);
	ft_strdel(&node_1);
	ft_strdel(&node_2);
	if (!elem_1 || !elem_2)
		exit_lem_in(map);
	node_edge(elem_1, elem_2);
}
