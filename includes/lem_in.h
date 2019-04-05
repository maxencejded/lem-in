/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:16:56 by tkobb             #+#    #+#             */
/*   Updated: 2019/04/05 14:55:16 by mjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "dict.h"

# define DICT_SIZE 256
# define COMMENT '#'
# define UINT unsigned int
# define UCHAR unsigned char

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
	int				used;
	UINT			height;
	t_flag			flag;
	t_visited		visited;
	t_edge			*edges;
}					t_node;

typedef struct		s_path
{
	t_node			**nodes;
	UINT			len;
	UINT			ants_nbr;
}					t_path;

typedef struct		s_paths
{
	t_path			*path;
	struct s_paths	*next;
}					t_paths;

# define FLAGS "apq"
# define FLAG_A 1
# define FLAG_P 2
# define FLAG_Q 4

void				flags(int ac, char **av, unsigned char *flags);

t_node				*parse(t_dict **map, UCHAR options);
t_node				*node_add(t_dict **map, t_node **start, char *s, t_flag f);
void				node_link(t_dict **map, char *str, int middle);
void				node_edge(t_dict **map, t_node *elem_1, t_node *elem_2);

int					shortest_paths(t_node *source, UINT n_ants, UCHAR options);
t_path				*init_path(t_node *sink, t_node **next);
t_path				*set_path(t_node *sink);
t_path				*create_path(size_t size);
t_paths				*create_paths(t_path *path);
void				set_edge_visited(t_node *a, t_node *b);

t_path				**dispatch(t_paths *paths, int n_ants, int *size);
void				execute(t_path **path, int n_ants, int size);

void				dict_print(t_dict **dict, size_t size);
void				print_paths(t_path **path, int size);

int					exit_lem_in(char *str, t_dict **map);
void				map_free(t_dict **map, size_t size);
void				node_free(t_node *node);
void				path_free(t_path **path, int size);
void				free_paths(t_paths *paths);

#endif
