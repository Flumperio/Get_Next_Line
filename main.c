#include "get_next_line.h"

int
main(void)
{
	int		r;
	char	*line;
	int 	fd;

	line = NULL;
	fd = open("/Users/juasanto/Desktop/New_GNL/New_GNL/get_next_line.c", O_RDONLY);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
	system("leaks New_GNL");
}
