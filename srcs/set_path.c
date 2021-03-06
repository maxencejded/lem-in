/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:01:05 by tkobb             #+#    #+#             */
/*   Updated: 2019/04/04 19:04:26 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

static t_node	*min_height(t_node *node)
{
	unsigned int	min_h;
	t_node			*neighbor_with_min_h;
	t_edge			*edge;

	neighbor_with_min_h = NULL;
	min_h = UINT_MAX;
	edge = node->edges;
	while (edge)
	{
		if (edge->node->flag != SINK && edge->node->height < min_h
			&& edge->node->visited == FALSE && edge->visited == FALSE
			&& (edge->node->height || edge->node->flag == SOURCE))
		{
			min_h = edge->node->height;
			neighbor_with_min_h = edge->node;
		}
		edge = edge->next;
	}
	return (neighbor_with_min_h);
}

UINT			validate_path(t_node *sink)
{
	UINT	len;
	t_node	*node;
	t_node	*next;

	len = 0;
	node = sink;
	while (node)
	{
		if (node->flag == SOURCE)
			return (len);
		if ((next = min_height(node)) == NULL || next->height >= node->height)
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
		next = min_height(node);
		set_edge_visited(node, next);
		set_edge_visited(next, node);
		node = next;
	}
	return (path);
}
