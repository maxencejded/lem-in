/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:01:05 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/14 17:18:47 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <limits.h>

static t_edge	*get_edge(t_node *from, t_node *to)
{
	t_edge	*edge;

	edge = from->edges;
	while (edge)
	{
		if (edge->node == to)
			return (edge);
		edge = edge->next;
	}
	return (NULL);
}

UINT			validate_path(t_node *sink)
{
	UINT	len;
	t_node	*node;
	t_node	*next;
	t_edge	*edge;

	len = 0;
	node = sink;
	while (node)
	{
		if (node->flag == SOURCE)
			return (len);
		if ((next = node->parent) == NULL)
			return (0);
		if ((edge = get_edge(node->parent, node)) == NULL
			|| edge->visited == TRUE)
			return (0);
		len += 1;
		node = next;
	}
	return (0);
}

t_path			*set_path(t_node *sink)
{
	UINT	len;
	t_node	*node;
	t_node	*next;
	t_path	*path;

	if ((len = validate_path(sink)) == 0)
		return (NULL);
	if ((path = create_path(len + 1)) == NULL)
		return (NULL);
	node = sink;
	while (node)
	{
		path->nodes[len] = node;
		if (node->flag == SOURCE || len == 0)
			break ;
		len--;
		node->visited = TRUE;
		next = node->parent;
		set_edge_visited(node, next);
		set_edge_visited(next, node);
		node = next;
	}
	return (path);
}
