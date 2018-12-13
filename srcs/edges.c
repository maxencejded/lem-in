/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:14 by mjacques          #+#    #+#             */
/*   Updated: 2018/12/13 13:16:10 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_edge	*edge_create(t_node *element)
{
	t_edge	*new;

	if (!(new = malloc(sizeof(t_edge))))
		return (NULL);
	new->node = element;
	new->next = NULL;
	return (new);
}

static void		edge_insert(t_node *element, t_edge *link)
{
	if (!element->edges)
		element->edges = link;
	else
	{
		link->next = element->edges;
		element->edges = link;
	}
}

void			node_edge(t_node *elem_1, t_node *elem_2)
{
	t_edge	*edge_1;
	t_edge	*edge_2;

	edge_1 = edge_create(elem_2);
	edge_2 = edge_create(elem_1);
	edge_insert(elem_1, edge_1);
	edge_insert(elem_2, edge_2);
}
