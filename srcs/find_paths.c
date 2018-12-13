#include "lem-in.h"
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
		if (edge->node->height < min_h)
		{
			min_h = edge->node->height;
			neighbor_with_min_h = edge->node;
		}
	}
	return (neighbor_with_min_h);
}

static t_path		*create_path(size_t size)
{
	t_path	*path;

	if ((path = (t_path*)malloc(sizeof(t_path))) == NULL)
		ft_error("not enough memory");
	if ((path->nodes = (t_node**)malloc(sizeof(t_node*) * size)) == NULL)
		ft_error("not enough memory");
	return (path);
}

t_paths				*create_paths(t_path *path)
{
	t_paths *p;

	if ((p = (t_paths*)malloc(sizeof(t_paths))) == NULL)
		return (NULL);
	p->path = path;
	p->next = NULL;
	return (p);
}

static void			add_path(t_paths **paths, t_node *end)
{
	/* trace back and take minimum height, make nodes as in use*/
	t_node	*node;
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
	if ((*paths = create_paths(path)) == NULL)
		ft_error("not enough memory");
	*paths = (*paths)->next;
}

static void			process_edges(t_node *node, t_queue **queue, unsigned int height)
{
	t_edge			*edge;

	edge = node->edges;
	while (edge)
	{
		if (edge->node->height == 0) /* we've never seen this node */ // Make sure no loops to start
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
	t_paths			*paths;
	t_paths			*cur_path;

	queue_add(&queue, graph);
	paths = NULL;
	cur_path = paths;
	while ((node = (t_node*)queue_pop(queue)))
	{
		if (node->flag == SINK)
		{
			add_path(&cur_path, node);
			if (node->height >= n_ants)
				break;
		}
		else
			process_edges(node, &queue, node->height + 1);
	}
	return (paths);
}
