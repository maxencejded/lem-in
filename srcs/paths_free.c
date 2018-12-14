#include "lem_in.h"

void	paths_free(t_paths *paths)
{
	t_paths	*cur;
	t_paths	*next;

	cur = paths;
	while (cur)
	{
		path_free(cur->path);
		next = cur->next;
		free(cur);
		cur = next;
	}
}
