/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:06:12 by mjacques          #+#    #+#             */
/*   Updated: 2019/04/05 00:41:22 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ptrlen(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

static t_node	*node_create(char *name, t_flag flag)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->name = ft_strdup(name);
	new->used = -1;
	new->visited = FALSE;
	new->height = 0;
	new->flag = flag;
	new->edges = NULL;
	return (new);
}

t_node			*node_add(t_dict **map, t_node **start, char *s, t_flag f)
{
	char	**split;
	t_node	*node;

	if ((split = ft_splitspace(s)) == NULL)
		exit_lem_in("Not enough Memory", map);
	if (ptrlen(split) != 3)
	{
		ft_strdel(&s);
		ft_ptrdel(split);
		return (NULL);
	}
	node = node_create(split[0], f);
	ft_ptrdel(split);
	if (node == NULL)
		exit_lem_in("Not enough Memory", map);
	dict_insert(map, DICT_SIZE, node->name, node);
	if (f == SOURCE)
		*start = node;
	return (node);
}

void			node_link(t_dict **map, char *str, int middle)
{
	char	*node_1;
	char	*node_2;
	t_node	*elem_1;
	t_node	*elem_2;

	node_1 = ft_strsub(str, 0, middle);
	node_2 = ft_strsub(str, middle + 1, ft_strlen(str) - middle - 1);
	elem_1 = (t_node *)dict_search(map, DICT_SIZE, node_1);
	elem_2 = (t_node *)dict_search(map, DICT_SIZE, node_2);
	ft_strdel(&node_1);
	ft_strdel(&node_2);
	if (!elem_1 || !elem_2)
	{
		ft_strdel(&str);
		node_free(elem_1);
		node_free(elem_2);
		exit_lem_in("ERROR", map);
	}
	node_edge(map, elem_1, elem_2);
}
