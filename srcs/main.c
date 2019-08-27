/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:22:15 by tkobb             #+#    #+#             */
/*   Updated: 2019/08/26 17:50:49 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ants_nbr(UCHAR options)
{
	int			nbr;
	char		*line;
	char		*end;

	nbr = 0;
	line = NULL;
	if (get_next_line(0, &line) > 0 && line)
	{
		nbr = ft_strtoi(line, &end);
		if (*end != '\0')
		{
			ft_strdel(&line);
			return (0);
		}
		(options & FLAG_Q) ? 0 : ft_putendl(line);
	}
	ft_strdel(&line);
	return (nbr);
}

int				main(int argc, char **argv)
{
	int			n_ants;
	UCHAR		options;
	t_dict		**map;
	t_node		*source;

	options = 0;
	map = NULL;
	flags(argc, argv, &options);
	if ((n_ants = ants_nbr(options)) <= 0)
		exit_lem_in("ERROR", map);
	if ((map = dict_init(DICT_SIZE)) == NULL)
		exit_lem_in("ERROR", map);
	if ((source = parse(map, options)) == NULL)
		exit_lem_in("ERROR", map);
	if (shortest_paths(source, n_ants, options) == 0)
		exit_lem_in("ERROR", map);
	map_free(map, DICT_SIZE);
	return (0);
}
