#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct			s_edge
{
	struct s_node		*node;
	struct s_edge		*next;
}						t_edge;

typedef struct			s_node
{
	char				*name;
	enum e_visited{
		TRUE, FALSE
	}					visited;
	unsigned int		height;
	enum e_flag{
		SOURCE, SINK, REGULAR
	}					flag;
	t_edge				*edges;
}						t_node;

# include "libft.h"

t_node			*parse(int fd, unsigned int *n_ants);
t_paths			*find_shortest_paths(t_node *graph, unsigned int n_ants)
int				execute(t_paths *paths, unsigned int n_ants);

#endif
