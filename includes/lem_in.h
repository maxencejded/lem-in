/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:16:56 by tkobb             #+#    #+#             */
/*   Updated: 2019/04/03 17:53:57 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "hash_map.h"

# define HASH_MAP_SIZE 256
# define COMMENT '#'
# define UINT unsigned int

typedef enum		e_visited
{
	TRUE, FALSE
}					t_visited;

typedef struct		s_edge
{
	t_visited		visited;
	struct s_node	*node;
	struct s_edge	*next;
}					t_edge;

typedef enum		e_flag
{
	SOURCE, SINK, REGULAR
}					t_flag;

typedef struct		s_node
{
	char			*name;
	UINT			used;
	UINT			height;
	t_flag			flag;
	t_visited		visited;
	t_edge			*edges;
}					t_node;

typedef struct		s_path
{
	t_node			**nodes;
	UINT			len;
}					t_path;

typedef struct		s_paths
{
	t_path			*path;
	struct s_paths	*next;
}					t_paths;

t_paths				*find_shortest_paths(t_node *graph, UINT n_ants);
int					execute(t_paths *paths, UINT n_ants);

void				h_map_print(t_hash **map, size_t size);
void				node_print(t_node *node);

t_node				*parse(t_hash **map);
t_node				*node_add(t_hash **map, t_node **start, char *s, t_flag f);
void				node_link(t_hash **map, char *str, int middle);
void				node_edge(t_hash **map, t_node *elem_1, t_node *elem_2);

t_path				*create_path(size_t size);
t_paths				*create_paths(t_path *path);
void				print_paths(t_paths *paths);
void				print_path(t_path *path);
void				set_edge_visited(t_node *a, t_node *b);

t_path				*init_path(t_node *sink, t_node **next);
t_path				*set_path(t_node *sink);

int					exit_lem_in(char *str, t_hash **map);
void				free_map(t_hash **map, size_t size);
void				node_free(t_node *node);
void				free_paths(t_paths *paths);
void				free_path(t_path *path);

#endif
