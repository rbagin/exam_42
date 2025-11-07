#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int		read_bytes = 0;
	static int		pos;
	static char		buf[BUFFER_SIZE]

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (read_bytes)
	}
}

#include <stdio.h>
#include <fcntl.h>

/*
cc -Wall -Wextra -Werror get_next_line.c
*/
int	main(void)
{
	int		fd;

	fd = open("test_file.txt", O_RDONLY);
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	return(0);
}
