/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:22:15 by tkobb             #+#    #+#             */
/*   Updated: 2019/04/04 20:31:08 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ants_nbr(void)
{
	int		nbr;
	char	*line;
	char	*end;

	nbr = 0;
	if (get_next_line(0, &line) && *line)
	{
		nbr = ft_strtoi(line, &end);
		if (*end != '\0')
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	return (nbr);
}

int			main(int argc, char **argv)
{
	int				size;
	int				n_ants;
	t_hash			**map;
	t_node			*graph;
	t_path			**path_use;

	size = 0;
	map = NULL;
	if (argc != 1 && argv[0])
		ft_error("Usage: ./lem-in");
	if ((n_ants = ants_nbr()) <= 0)
		exit_lem_in("ERROR", map);
	if ((map = h_map_create(HASH_MAP_SIZE)) == NULL)
		exit_lem_in("ERROR", map);
	if ((graph = parse(map)) == NULL)
		exit_lem_in("ERROR", map);
	if ((path_use = shortest_paths(graph, n_ants, &size)) == NULL)
		exit_lem_in("ERROR", map);
	ft_printf("Ants: %d\n", n_ants);
	execute(path_use, n_ants, size);
	free_path(path_use, size);
	free_map(map, HASH_MAP_SIZE);
	return (0);
}
