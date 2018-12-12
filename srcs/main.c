#include "lem-in.h"

#define MIN(x, y) ((x) < (y)) ? (x) : (y)

typedef struct				s_neighbors
{
	struct s_node			*node;
	int						flux_in;
	int						flux_out;
	int						flux_max;
	struct s_neighbors		*next;
}							t_neighbors;

typedef struct				s_node
{
	char					*name;
	enum	e_act{YES, NO}	e_active;
	unsigned int			height;
	unsigned int			excess;
	t_neighbors				*neighbors;

}							t_node;

t_node		*create_node(char *name)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->name = ft_strdup(name);
	new->e_active = YES;
	new->height = 0;
	new->excess = 0;
	new->neighbors = NULL;
	return (new);
}

typedef struct				s_hashtable
{
	int						key;
	void					*data;
	struct s_hashtable		*next;
}							t_hashtable;

// void					push(t_node *parent, t_node *child)
// {
// 	int		flow;
//
// 	flow = MIN(parent->excess, (parent->flux_max - parent->flux_out));
// 	if ((parent->height <= child->height + 1) && parent->excess > 0 && (parent->flux_max - parent->flux_out) > 0)
// 	{
// 		parent->excess -= flow;
// 		child->excess += flow;
// 		parent->neighbors->flux_out += flow;
// 		parent->neighbors->flux_in -= flow;
// 	}
// }
//
// void					relabel(t_node *elem)
// {
// 	t_list			*tmp;
// 	unsigned int	height;
//
// 	tmp = elem->neighbors;
// 	height = tmp->node->height;
// 	while (tmp->next)
// 	{
// 		height = MIN(height, tmp->node->height);
// 		tmp = tmp->next;
// 	}
// 	elem->height = height + 1;
// }
//
// void					decharge(t_node *elem)
// {
// 	t_list			*tmp;
//
// 	tmp = elem->neighbors;
// 	while (tmp->next && elem->excess > 0)
// 	{
// 		push(elem, tmp->node);
// 		tmp = tmp->next;
// 	}
// 	relabel(elem);
// }
//
// void					relabel_front(t_node *start, t_node *end)
// {
// 	t_list	*tmp;
//
// 	tmp = start->neighbors;
// 	while (tmp->next)
// 	{
// 		push(start, tmp->node);
// 		tmp = tmp->next;
// 	}
// }

// int						check_active(unsigned int *active, unsigned int total)
// {
// 	unsigned int	i;
// 	unsigned int	res;
//
// 	i = 0;
// 	res = 0;
// 	while (i < total)
// 	{
// 		if (active[i] == ACTIVE)
// 			res += 1;
// 		i++;
// 	}
// 	return ((res == 0) ? INACTIVE : ACTIVE);
// }
//
// t_node					*push_label(t_node *start, t_node *end, unsigned int total)
// {
// 	// The init part will be done while we are creating the graph
// 	while (total > 0)
// 	{
// 		push
// 	}
//
// }

int		main(int argc, char **argv)
{
//	char	*line;
//	char 	*document;

	// t_node		node_1 = {
	// 	"01", ACTIVE, 0, 0, 1, {
	// 		{&node_2, 0, 0, 1},
	// 		{&node_3, 0, 0, 1},
	// 		NULL
	// 	}
	// };
    //
	// t_node		node_2 = {
	// 	"02", ACTIVE, 0, 0, 2, {
	// 		{&node_1, 0, 0, 1},
	// 		{&node_3, 0, 0, 1},
	// 		{&node_4, 0, 0, 1},
	// 		NULL
	// 	}
	// };
    //
	// t_node		node_3 = {
	// 	"03", ACTIVE, 0, 0, 3, {
	// 		{&node_1, 0, 0, 1},
	// 		{&node_2, 0, 0, 1},
	// 		{&node_4, 0, 0, 1},
	// 		NULL
	// 	}
	// };
    //
	// t_node		node_4 = {
	// 	"04", ACTIVE, 0, 0, 4, {
	// 		{&node_2, 0, 0, 1},
	// 		{&node_3, 0, 0, 1},
	// 		NULL
	// 	}
	// };

	if (argc != 1 && argv[0])
		ft_error("Usage: ./lem-in");
//	document = ft_strnew(0);
//	while ((get_next_line(0, &line) > 0) && *line)
//		document = free_join(document, line);
//	ft_putendl(document);
	return (0);
}
