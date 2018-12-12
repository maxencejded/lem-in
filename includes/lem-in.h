#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

t_node			*parse(int fd, unsigned int *n_ants);
t_paths			*find_shortest_paths(t_node *graph, unsigned int n_ants)
int				execute(t_paths *paths, unsigned int n_ants);

#endif
