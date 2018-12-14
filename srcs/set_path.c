#include <lem_in.h>
#include <limits.h>

static t_node	*get_neighbor_with_min_height(t_node *node)
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

t_path			*init_path(t_node *sink, t_node **next)
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
	set_edge_visited(node, sink);
	set_edge_visited(sink, node);
	*next = node;
	return (path);
}

t_path			*set_path(t_node *sink)
{
	UINT	len;
	t_node	*node;
	t_node	*next;
	t_path	*path;

	path = init_path(sink, &node);
	len = path->len - 1;
	while (node)
	{
		path->nodes[len] = node;
		if (node->flag == SOURCE)
			break ;
		len--;
		node->visited = TRUE;
		if ((next = get_neighbor_with_min_height(node)) == NULL)
			break ;
		set_edge_visited(node, next);
		set_edge_visited(next, node);
		node = next;
	}
	return (len == 0 ? path : path_free(path));
}
