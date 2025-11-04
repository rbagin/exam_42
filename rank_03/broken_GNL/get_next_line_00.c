#include "get_next_line.h"


// 1st practice try, got it right after 40min :))
char	*strjoin_char(char *s, int c)
{
	char	*new_s;
	int		strlen = 0;
	int		i = 0;

	if (s)
		while (s[strlen])
			strlen++;
	if (!(new_s = malloc(strlen + 2)))
		return(free(s), NULL);
	while(i < strlen)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = c;
	new_s[i + 1] = '\0';
	free(s);
	return(new_s);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	pos = 0;
	static int	read_bytes = 0;
	char	*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (pos >= read_bytes)
		{
			pos = 0;
			read_bytes = read(fd, buf, BUFFER_SIZE);
			if (read_bytes <= 0)
				return(line);
		}
		if (!(line = strjoin_char(line, buf[pos])))
			return(NULL);
		if (buf[pos++] == '\n')
			return(line);
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
