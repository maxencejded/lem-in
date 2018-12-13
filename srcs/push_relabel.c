#include "lem_in.h"

#define MIN(x, y) ((x) < (y)) ? (x) : (y)

typedef struct			s_edge
{
	struct s_node		*node;
	int					flow_in;
	int					flow_out;
	int					flow_max;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_node
{
	char				*name;
	UINT		height;
	int					excess;
	UINT		visited;
	enum t_flag{
		SOURCE, SINK, REGULAR
	}					t_flag;
	t_edge				*edges;
}						t_node;

// typedef struct			s_hashtable
// {
// 	int					key;
// 	void				*data;
// 	struct s_hashtable	*next;
// }						t_hashtable;


t_node		*create_node(char *name)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->name = ft_strdup(name);
	new->height = 0;
	new->excess = 0;
	new->t_flag = REGULAR;
	new->edges = NULL;
	return (new);
}


void	recursive_get_node_with_excess(t_node *node, UINT *max_h, t_node **node_max_h, UINT visited_token)
{
	t_edge	*edge;

	if (node->excess > 0 && node->height > *max_h)
	{
		*max_h = node->height;
		*node_max_h = node;
	}
	edge = node->edges;
	while (edge)
	{
		if (edge->node->visited != visited_token)
		{
			edge->node->visited = visited_token;
			recursive_get_node_with_excess(edge->node, max_h, node_max_h, visited_token);
		}
		edge = edge->next;
	}
}

t_node		*get_node_with_excess(t_node *graph)
{
	UINT		max_h;
	static UINT	visited_token = 0;
	t_node	*node_max_h;

	node_max_h = NULL;
	max_h = -1;
	visited_token += 1;
	recursive_get_node_with_excess(graph, &max_h, &node_max_h, visited_token);
	return (node_max_h);
}

t_node		*get_downhill_neighbor(t_node *node)
{
	t_edge	*tmp;

	tmp = node->edges;
	while (tmp)
	{
		if (tmp->node->height == (node->height - 1) && (tmp->flow_max - tmp->flow_out) > 0)
			return (tmp->node);
		tmp = tmp->next;
	}
	return (NULL);
}

t_edge		*find_edge(t_node *parent, char *name)
{
	t_edge	*tmp;

	tmp = parent->edges;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->node->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		push(t_node *parent, t_node *child)
{
	int		flow;
	t_edge	*edge;

	edge = find_edge(parent, child->name);
	flow = MIN(parent->excess, (edge->flow_max - edge->flow_out));
	// if ((parent->height <= child->height + 1) && parent->excess > 0 && (parent->flow_max - parent->flow_out) > 0)
	// {
		parent->excess -= flow;
		child->excess += flow;
		edge->flow_out += flow;
		edge->flow_in -= flow;
	// }
}

void		pr_max_flow(t_node *graph)
{
	t_node	*v;
	t_node	*w;

	while ((v = get_node_with_excess(graph)))
		if ((w = get_downhill_neighbor(v)) == NULL)
			v->height += 1;
		else
			push(v, w);
}


t_edge		*create_edge(t_node *node)
{
	t_edge	*new;

	if (!(new = (t_edge *)malloc(sizeof(t_edge))))
		return (NULL);
	new->node = node;
	new->flow_in = 0;
	new->flow_out = 0;
	new->flow_max = 1;
	new->next = NULL;
	return (new);
}

int		main(int argc, char **argv)
{
//	char	*line;
//	char 	*document;

	if (argc != 1 && argv[0])
		ft_error("Usage: ./lem-in");
	// Find the numbers of nodes to add to the S
	t_node	*node_4 = create_node("Node_4");
	node_4->t_flag = SINK;
	t_node	*node_3 = create_node("Node_3");
	t_node	*node_2 = create_node("Node_2");
	t_node	*node_1 = create_node("Node_1");
	node_4->t_flag = SOURCE;
	node_3->edges = create_edge(node_4);
	node_2->edges = create_edge(node_3);
	node_2->edges->next = create_edge(node_4);
	node_1->edges = create_edge(node_2);
	node_1->edges->next = create_edge(node_3);

	pr_max_flow(node_1);
//	document = ft_strnew(0);
//	while ((get_next_line(0, &line) > 0) && *line)
//		document = free_join(document, line);
//	ft_putendl(document);
	return (0);
}
