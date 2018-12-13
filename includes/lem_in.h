#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "hash_map.h"

# define HASH_MAP_SIZE 256
# define COMMENT_CHAR '#'
# define UINT unsigned int

typedef struct		s_edge
{
	struct s_node	*node;
	struct s_edge	*next;
}					t_edge;

typedef enum		e_flag
{
	SOURCE, SINK, REGULAR
}					t_flag;

typedef enum		e_visited
{
	TRUE, FALSE
}					t_visited;

typedef struct		s_node
{
	char			*name;
	UINT			height;
	t_flag			flag;
	t_visited		visited;
	t_edge			*edges;
}					t_node;

typedef struct		s_path
{
	t_node			*nodes;
	UINT			len;
}					t_path;

typedef struct		s_paths
{
	t_path			*path;
	struct s_paths	*next;
}					t_paths;

t_paths				*find_shortest_paths(t_node *graph, UINT n_ants);
int					execute(t_paths *paths, UINT n_ants);

int					exit_lem_in(t_hash **map);
void				free_map(t_hash **map, size_t size);

void				h_map_print(t_hash **map, size_t size);

/*
**	Parsing
*/
UINT				ants_nbr(int fd);
t_node				*parse(int fd, t_hash **map);

t_node				*node_create(char *name);
void				node_free(t_node *node);
void				node_print(t_node *node);

t_node				*node_insert(char *str, t_flag flag, t_hash **map);
void				node_edge(t_node *elem_1, t_node *elem_2);
void				node_link(char *str, t_hash **map, int position);

#endif
