/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:22:15 by tkobb             #+#    #+#             */
/*   Updated: 2018/12/17 05:26:45 by theo             ###   ########.fr       */
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
	if (argc != 1 && argv[0])
		ft_error("Usage: ./lem-in");
	if ((n_ants = ants_nbr(0)) == 0)
		exit_lem_in("ERROR", map);
	if ((map = h_map_create(HASH_MAP_SIZE)) == NULL)
		exit_lem_in("ERROR", map);
	if ((graph = parse(0, map)) == NULL)
		exit_lem_in("ERROR", map);
	if ((paths = find_shortest_paths(graph, n_ants)) == NULL)
		exit_lem_in("ERROR", map);
	ft_printf("Ants: %d\n", n_ants);
	h_map_print(map, HASH_MAP_SIZE);
	print_paths(paths);
	execute(paths, n_ants);
	free_paths(paths);
	free_map(map, HASH_MAP_SIZE);
	return (0);
}
