#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

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
	t_edge				*edges;
}						t_node;

typedef struct			s_path
{
	t_node				*nodes;
	unsigned int		len;
}						t_path;

typedef struct			s_paths
{
	t_path				*path;
	struct s_paths		*next;
}						t_paths;

t_node			*parse(int fd, unsigned int *n_ants);
t_paths			*find_shortest_paths(t_node *graph, unsigned int n_ants);
int				execute(t_paths *paths, unsigned int n_ants);

#endif
