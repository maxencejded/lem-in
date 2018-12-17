/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:22:15 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/17 05:14:31 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_hash			**map;
	t_node			*graph;
	t_paths			*paths;
	UINT			n_ants;

	map = NULL;
	int fd = open("maps/1.map", O_RDONLY);
	if (argc != 1 && argv[0])
		ft_error("Usage: ./lem-in");
	if ((n_ants = ants_nbr(fd)) == 0)
		exit_lem_in("ERROR", map);
	if ((map = h_map_create(HASH_MAP_SIZE)) == NULL)
		exit_lem_in("ERROR", map);
	if ((graph = parse(fd, map)) == NULL)
		exit_lem_in("ERROR", map);
	if ((paths = find_shortest_paths(graph, n_ants)) == NULL)
		exit_lem_in("ERROR", map);
	ft_printf("Ants: %d\n", n_ants);
	h_map_print(map, HASH_MAP_SIZE);
	execute(paths, n_ants);
	free_paths(paths);
	free_map(map, HASH_MAP_SIZE);
	return (0);
}
