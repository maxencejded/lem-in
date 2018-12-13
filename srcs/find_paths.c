#include "lem-in.h"

static t_node		*get_neighbor_with_min_height(t_node *node)
{
	return (NULL);
}

static void			add_path(t_paths **paths, t_node *end)
{
	/* trace back and take minimum height, make nodes as in use*/
	t_node	*node;
	t_node	*next;
	t_path	*path;

	if ((path = create_path(end->height + 1)) == NULL)
		ft_error("not enough memory");
	node = end;
	while (node)
	{
		path->nodes[node->height] = node;
		if (node->flag == SOURCE)
			break;
		// node->visited = TRUE;
		node = get_neighbor_with_min_height(node);
	}
}

static void			process_edges(t_node *node, t_queue **queue, unsigned int height)
{
	t_edge			*edge;

	edge = node->edges;
	while (edge)
	{
		if (edge->node->height == 0 && edge->node->flag != SOURCE) /* we've never seen this node */
		{
			edge->node->height = height;
			queue_add(&queue, edge->node);
		}
		edge = edge->next;
	}
}

t_paths				*find_shortest_paths(t_node *graph, unsigned int n_ants)
{
	t_queue			*queue;
	t_node			*node;
	t_paths			*paths;

	queue_add(&queue, graph);
	while ((node = (t_node*)queue_pop(queue)))
	{

		if (node->flag == SINK)
		{
			if (path = (t_path*)malloc(node->height + 1) == NULL)
				ft_error("not enough memory");
			add_path(&paths, node);
			if (node->height >= n_ants)
				break;
		}
		else
			process_edges(node, &queue, node->height + 1);
	}
	return (paths);
}
