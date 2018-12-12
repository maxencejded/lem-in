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
	t_edge				*edges;
}						t_node;

# include "libft.h"

#endif
