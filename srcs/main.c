#include "lem-in.h"

int		main(int argc, char **argv)
{
	t_node			*graph;
	t_paths			*paths;
	unsigned int	n_ants;

	if (argc != 1 && argv[0])
		ft_error("Usage: ./lem-in");
	n_ants = 0;
	if((graph = parse(0, &n_ants)) == NULL)
		ft_error("Error");
	if ((paths = find_shortest_paths(graph, n_ants)) == NULL)
		ft_error("Error");
	execute(paths, n_ants);
	return (0);
}
