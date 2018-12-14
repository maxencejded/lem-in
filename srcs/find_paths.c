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
			if (tail && tail->path->len >= n_ants)
				break ;
		}
		else
			process_edges(node, &queue, node->height + 1);
	}
	// print_paths(head);
	queue_free(queue);
	return (head);
}
