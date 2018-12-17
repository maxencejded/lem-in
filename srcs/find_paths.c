/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:41:47 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/17 05:06:12 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <queue.h>

static int			add_path(t_paths **tail, t_node *end)
{
	t_path	*path;
	t_paths	*next;

	if ((path = set_path(end)) == NULL)
		return (1);
	if ((next = create_paths(path)) == NULL)
		ft_error("not enough memory");
	if (*tail)
	{
		(*tail)->next = next;
		*tail = (*tail)->next;
	}
	else
		*tail = next;
	return (0);
}

static void			process_edges(t_node *node, t_queue **queue)
{
	t_edge			*edge;

	edge = node->edges;
	while (edge)
	{
		if ((edge->node->height == 0 && edge->node->flag != SOURCE)
			|| edge->node->flag == SINK)
		{
			edge->node->height = node->height + 1;
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
			queue_free(queue);
			if (add_path(tail, node))
				return (0);
			return (1);
		}
		process_edges(node, &queue);
	}
	queue_free(queue);
	return (0);
}

void				reset_heights(t_node *graph)
{
	t_edge	*edge;

	if ((graph->height == 0 && graph->flag != SOURCE)
		|| graph->visited == TRUE)
		return ;
	graph->height = 0;
	edge = graph->edges;
	while (edge)
	{
		reset_heights(edge->node);
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
		reset_heights(graph);
	}
	return (head);
}
