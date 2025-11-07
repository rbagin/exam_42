#define _GNU_SOURCE

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*read_input(void)
{
	int		read_bytes = 0;
	int		total_len = 0;
	char	buf[BUFFER_SIZE];
	char	*input = NULL;
	char	*temp = NULL;

	while ((read_bytes = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0)
	{
		temp = realloc(input, total_len + read_bytes + 1);
		if (!temp)
		{
			perror("error\n");
			free(input);
			return (NULL);
		}
		input = temp;
		memmove(input + total_len, buf, read_bytes);
		total_len += read_bytes;
		input[total_len] = '\0';
		read_bytes = 0;
	}
	if (read_bytes < 0)
	{
		perror("error\n");
		free(input);
		return (NULL);
	}
	return (input);
}

void	print_stars(int len)
{
	int i = 0;
	while(i < len)
	{
		write(1 , "*", 1);
		i++;
	}
}

int	process_input(char	*filter)
{
	int	filter_len = strlen(filter);
	char	*input = read_input();
	char	*current = input;
	char	*match;
	if (!input)
		return (1);
	while(*current)
	{
		match = memmem(current, strlen(current), filter, filter_len);
		if (match == current)
		{
			print_stars(filter_len);
			current += filter_len;
		}
		else
		{
			write(1 , current, 1);
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
