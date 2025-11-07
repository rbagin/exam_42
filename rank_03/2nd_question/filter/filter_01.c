#define _GNU_SOURCE

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*read_input(void)
{
	char	buf[BUFFER_SIZE];
	int	read_bytes = 0;
	int	total_len = 0;
	char	*tmp;
	char	*input = NULL;

	while ((read_bytes = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0)
	{
		tmp = realloc(input, total_len + read_bytes + 1);
		if (!tmp)
		{
			free(input);
			return (NULL);
		}
		input = tmp;
		memmove(input + total_len, buf, read_bytes);
		total_len += read_bytes;
		input[total_len] = '\0';
		read_bytes = 0;
	}
	if (read_bytes < 0)
	{
		free(input);
		return (NULL);
	}
	return (input);
}

void	print_stars(int len)
{
	while(len > 0)
	{
		write(1, "*", 1);
		len--;
	}
}

int	process_input(char *filter)
{
	char *input = read_input();
	int		filter_len = strlen(filter);
	char	*current;
	char	*match;

	if (!input)
	{
		fprintf(stderr , "error\n");
		return (1);
	}
	current = input;
	while (*current)
	{
		match = memmem(current, strlen(current), filter, filter_len);
		if (match == current)
		{
			print_stars(filter_len);
			current += filter_len;
		}
		else
		{
			write(1, current, 1);
			current++;
		}
	}
	free(input);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
		return (1);
	return (process_input(argv[1]));
}
