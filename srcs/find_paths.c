#include <lem_in.h>
#include <queue.h>
#include <limits.h>

static t_node		*get_neighbor_with_min_height(t_node *node)
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
			&& edge->node->visited == FALSE)
		{
			min_h = edge->node->height;
			neighbor_with_min_h = edge->node;
		}
		edge = edge->next;
	}
	return (neighbor_with_min_h);
}

static t_path		*set_path(t_node *sink)
{
	UINT	len;
	t_node	*node;
	t_path	*path;

	if ((node = get_neighbor_with_min_height(sink)) == NULL)
		ft_error("no neighbor");
	len = node->height + 1;
	if ((path = create_path(len + 1)) == NULL)
		ft_error("not enough memory");
	path->nodes[len] = sink;
	while (node)
	{
		path->nodes[node->height] = node;
		if (node->flag == SOURCE)
			break ;
		node->visited = TRUE;
		node = get_neighbor_with_min_height(node);
	}
	return (path);
}

static void			add_path(t_paths **tail, t_node *end)
{
	t_path	*path;
	t_paths	*next;

	path = set_path(end);
	if ((next = create_paths(path)) == NULL)
		ft_error("not enough memory");
	if (*tail)
		(*tail)->next = next;
	else
		*tail = next;
}

static void			process_edges(t_node *node,
	t_queue **queue, unsigned int height)
{
	t_edge			*edge;

	edge = node->edges;
	while (edge)
	{
		if ((edge->node->height == 0 && edge->node->flag != SOURCE)
			|| edge->node->flag == SINK)
		{
			edge->node->height = height;
			queue_add(queue, edge->node);
		}
		edge = edge->next;
	}
}

t_paths				*find_shortest_paths(t_node *graph, unsigned int n_ants)
{
	t_queue			*queue;
	t_node			*node;
	t_paths			*head;
	t_paths			*tail;

	queue = NULL;
	queue_add(&queue, graph);
	tail = NULL;
	head = tail;
	while ((node = (t_node*)queue_pop(queue)))
	{
		if (node->flag == SINK)
		{
			add_path(&tail, node);
			if (head == NULL)
				head = tail;
			if (node->height >= n_ants)
				break ;
		}
		else
			process_edges(node, &queue, node->height + 1);
	}
	print_paths(head);
	queue_free(queue, NULL);
	return (head);
}
