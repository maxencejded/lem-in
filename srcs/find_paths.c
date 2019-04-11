/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:41:47 by tkobb             #+#    #+#             */
/*   Updated: 2019/04/10 15:56:11 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "queue.h"

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

static int			find_shortest_path(t_node *source, t_paths **tail)
{
	t_queue	*queue;
	t_node	*node;

	queue = NULL;
	queue_add(&queue, source);
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

int					shortest_paths(t_node *source, UINT n_ants, UCHAR options)
{
	int				size;
	t_paths			*head;
	t_paths			*tail;
	t_path			**paths;

	size = 0;
	tail = NULL;
	head = NULL;
	while ((find_shortest_path(source, &tail)))
	{
		if (head == NULL)
			head = tail;
		reset_heights(source);
	}
	if (head == NULL)
		return (0);
	if ((paths = dispatch(head, n_ants, &size)) == NULL)
		return (0);
	(options & FLAG_P) ? print_paths(paths, size) : 0;
	(options & FLAG_Q) ? 0 : ft_printf("Ants: %d\n", n_ants);
	execute(paths, n_ants, size);
	path_free(paths, size);
	return (1);
}
