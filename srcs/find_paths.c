/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:41:47 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/14 15:55:18 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <queue.h>

static void			add_path(t_paths **tail, t_node *end)
{
	t_path	*path;
	t_paths	*next;

	if ((path = set_path(end)) == NULL)
		return ;
	if ((next = create_paths(path)) == NULL)
		ft_error("not enough memory");
	if (*tail)
	{
		(*tail)->next = next;
		*tail = (*tail)->next;
	}
	else
		*tail = next;
}

static void			process_edges(t_node *node, t_queue **queue)
{
	t_edge			*edge;

	edge = node->edges;
	while (edge)
	{
		if ((edge->node->parent == NULL && edge->node->flag != SOURCE)
			|| (edge->node->flag == SINK && edge->visited == FALSE
			&& node->visited == FALSE))
		{
			edge->node->parent = node;
			queue_add(queue, edge->node);
		}
		edge = edge->next;
	}
}

int					find_shortest_path(t_node *graph, t_paths **tail)
{
	t_queue	*queue;
	t_node	*node;

	queue = NULL;
	queue_add(&queue, graph);
	while ((node = queue_pop(queue)))
	{
		if (node->flag == SINK)
		{
			add_path(tail, node);
			queue_free(queue);
			return (1);
		}
		process_edges(node, &queue);
	}
	queue_free(queue);
	return (0);
}

void				reset_parents(t_node *graph)
{
	t_edge	*edge;

	if ((graph->parent == NULL && graph->flag != SOURCE) || graph->visited == TRUE)
		return ;
	graph->parent = NULL;
	edge = graph->edges;
	while (edge)
	{
		reset_parents(edge->node);
		edge = edge->next;
	}
}

t_paths				*find_shortest_paths(t_node *graph, unsigned int n_ants)
{
	t_paths			*head;
	t_paths			*tail;

	tail = NULL;
	head = tail;
	while ((find_shortest_path(graph, &tail)))
	{
		if (head == NULL)
			head = tail;
		if (tail && tail->path->len >= n_ants)
			break ;
		reset_parents(graph);
	}
	return (head);
}
