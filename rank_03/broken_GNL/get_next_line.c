#include "get_next_line.h"

static char *ft_strjoin_char(char *s, char c)
{
    char *new;
    int i = 0;
    int len = 0;

    if (s)
        while (s[len])
            len++;
    if (!(new = malloc(len + 2)))
	{
		free(s);
        return (NULL);
	}
		while (i < len)
    {
        new[i] = s[i];
        i++;
    }
    new[i] = c;
    new[i + 1] = '\0';
    free(s);
    return (new);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static int buffer_pos = 0;
    static int buffer_read = 0;
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                return (line);
        }
        if (!(line = ft_strjoin_char(line, buffer[buffer_pos])))
            return (NULL);
        if (buffer[buffer_pos++] == '\n')
            return (line);
    }
}

#include <stdio.h>
#include <fcntl.h>

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
