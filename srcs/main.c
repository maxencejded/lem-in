#include "lem-in.h"

#define MIN(x, y) ((x) < (y)) ? (x) : (y)
#define ACTIVE 0b1
#define INACTIVE 0b0

typedef enum			e_active
{
    ACTIVE, INACTIVE
}						t_active;

typedef struct			s_node
{
	char				*name;
	t_active			active;
	unsigned int		height;
	unsigned int		excess;
	unsigned int		index;

	typedef struct		s_list
	{
		struct s_node	*node;
		int				flux_in;
		int				flux_out;
		int				flux_max;
		struct s_list	*next;
	}					t_list;
	t_list				*neighbors;

}						t_node;

void					push(t_node *parent, t_node *child)
{
	int		flow;

	flow = MIN(parent->excess, (parent->flux_max - parent->flux_out));
	if ((parent->height <= child->height + 1) && parent->excess > 0 && (parent->flux_max - parent->flux_out) > 0)
	{
		parent->excess -= flow;
		child->excess += flow;
		parent->neighbors->flux_out += flow;
		parent->neighbors->flux_in -= flow;
	}
}

void					relabel(t_node *elem)
{
	t_list			*tmp;
	unsigned int	height;

	tmp = elem->neighbors;
	height = tmp->node->height;
	while (tmp->next)
	{
		height = MIN(height, tmp->node->height);
		tmp = tmp->next;
	}
	elem->height = height + 1;
}

void					decharge(t_node *elem)
{
	t_list			*tmp;

	tmp = elem->neighbors;
	while (tmp->next && elem->excess > 0)
	{
		push(elem, tmp->node);
		tmp = tmp->next;
	}
	relabel(elem);
}

void					relabel_front(t_node *start, t_node *end)
{
	t_list	*tmp;

	tmp = start->neighbors;
	while (tmp->next)
	{
		push(start, tmp->node);
		tmp = tmp->next;
	}
}

// algorithme réétiqueter-vers-l’avant(G(V,E),s,t):
//    pour tout voisin v  de s
//       pousser(s,v);              ceci sature les arcs
//
//
//     {\displaystyle (s,v)}
//
// (s,v) puisque le flot partant de
//
//
//     {\displaystyle s}
//
// s n'est pas limité
//    L = Liste(V-{s,t});           créer une liste des sommets
//    u = L.tête;
//    tantque (u != NIL):
//       H = h(u);
//       décharger(u);
//       si h(u) > H
//          placer u en tête de L
//       sinon
//          u = u.suivant;


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

t_node					*push_label(t_node *start, t_node *end, unsigned int total)
{
	// The init part will be done while we are creating the graph
	while (total > 0)
	{
		push
	}

}

int		main(int argc, char **argv)
{
//	char	*line;
//	char 	*document;

	t_node		node_1 = {
		"01", ACTIVE, 0, 0, 1, {
			{&node_2, 0, 0, 1},
			{&node_3, 0, 0, 1},
			NULL
		}
	};

	t_node		node_2 = {
		"02", ACTIVE, 0, 0, 2, {
			{&node_1, 0, 0, 1},
			{&node_3, 0, 0, 1},
			{&node_4, 0, 0, 1},
			NULL
		}
	};

	t_node		node_3 = {
		"03", ACTIVE, 0, 0, 3, {
			{&node_1, 0, 0, 1},
			{&node_2, 0, 0, 1},
			{&node_4, 0, 0, 1},
			NULL
		}
	};

	t_node		node_4 = {
		"04", ACTIVE, 0, 0, 4, {
			{&node_2, 0, 0, 1},
			{&node_3, 0, 0, 1},
			NULL
		}
	};


	if (argc != 1 && argv[0])
		ft_error("Usage: ./lem-in");
//	document = ft_strnew(0);
//	while ((get_next_line(0, &line) > 0) && *line)
//		document = free_join(document, line);
//	ft_putendl(document);
	return (0);
}
