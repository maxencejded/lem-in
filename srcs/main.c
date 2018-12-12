#include "lem-in.h"

int		main(int argc, char **argv)
{
	char	*line;
	char 	*document;

	if (argc != 1 && argv[0])
		ft_error("Usage: ./lem-in");
		document = ft_strnew(0);
	while ((get_next_line(0, &line) > 0) && *line)
		document = free_join(document, line);
	ft_putendl(document);
}
